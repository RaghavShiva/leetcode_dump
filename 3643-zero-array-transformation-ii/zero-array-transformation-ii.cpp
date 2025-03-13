class Solution {
public:
    bool helper(vector<int>& nums,vector<vector<int>>& queries,int n,int q){
         vector<long long>v(n+1,0);
        for(int i=0;i<q;i++){
            v[queries[i][0]]+=queries[i][2];
            v[queries[i][1]+1]-=queries[i][2];
        }
        for(int i=1;i<=n;i++){
            v[i]+=v[i-1];
            if(v[i-1]<nums[i-1])
            return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int l=0,r=q;
        int ans=-1;
        while(l<=r){
            int m = (l+r)/2;
            if(helper(nums,queries,n,m)){
                r=m-1;
                ans=m;
            }
            else
                l=m+1;
        }
        return ans;
    }
};
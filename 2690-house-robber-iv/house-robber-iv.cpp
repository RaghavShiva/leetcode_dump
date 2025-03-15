class Solution {
public:
    bool helper(int m, vector<int>nums,int k){
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=m){
                i++;
                k--;
            }
        }
        return k<=0;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int r = *max_element(nums.begin(),nums.end());
        int l = 1;
        int ans=0;
        while(l<=r){
            int m = (l+r)/2;
            if(helper(m,nums,k)){
                ans = m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};
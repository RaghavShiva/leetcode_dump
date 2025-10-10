class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        set<pair<int,int>>s;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int j = 0;
        for(int i=0;i<n;i++){
            j = upper_bound(nums.begin()+j,nums.end(),nums[i]+k)-nums.begin();
            if(nums[j-1]==k+nums[i] && i!=j-1){
                s.insert({nums[i],nums[j-1]});
                // j++;
            }
            else{
                j--;
            }
        } 
        ans = s.size();
        return ans;
    }
};
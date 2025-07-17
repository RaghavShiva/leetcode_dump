class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k,vector<int>(k,0));
         int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%k;
        }
        int ans = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                int prev = (j-nums[i]+k)%k;
                dp[nums[i]][j]=max(dp[nums[i]][j],1+dp[prev][j]);
                ans = max(ans,dp[nums[i]][j]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        int pick = nums[i]+solve(i-2,nums,dp);
        int notpick = solve(i-1,nums,dp);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int p = nums[i-1]+dp[i-2];
            int np = dp[i-1];
            dp[i]=max(p,np);
        }
        return dp[n];

    
  
    }
};
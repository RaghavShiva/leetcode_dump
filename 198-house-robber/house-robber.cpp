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
        int ptp=0,pr;
        pr=nums[0];
        for(int i=2;i<=n;i++){
            int p = nums[i-1]+ptp;
            int np = pr;
            ptp=pr;
            pr=max(p,np);
        }
        return pr;

    
  
    }
};
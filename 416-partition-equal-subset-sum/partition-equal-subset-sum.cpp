class Solution {
public:
    bool helper(vector<int>& nums, int i, int t,  vector<vector<int>> &dp){
        // base cases
        if(t==0){
            return true;
        }
        if(t<0){
            return false;
        }
        if(i<0){
            return false;
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
    // main logic
        bool taken = helper(nums,i-1,t-nums[i],dp);
        bool not_taken = helper(nums,i-1,t,dp);
        // updating state
        dp[i][t] = taken|not_taken;
        return dp[i][t];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        // sum is odd
        if(sum%2!=0){
            return false;
        }

        int target = sum/2;
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        // space-200*(100*200)
        // n*sum;
        return helper(nums,n-1,target,dp);
    }
};

// tc - O(n*sum)
// sc - O(n*sum)+stack space
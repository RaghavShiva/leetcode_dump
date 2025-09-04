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
        vector<bool> cur(target+1,false);
        cur[0]=true;

        for(int i=1;i<=n;i++){
            cur[0]=true;
            for(int j=target;j>=0;j--){
                bool not_taken = cur[j];
                bool taken = false;
                if(j>=nums[i-1]){
                    taken = cur[j-nums[i-1]];
                }
                cur[j] = taken|not_taken;
            }
        }
        return cur[target];
    }
};

// tc - O(n*sum)
// sc - O(sum) // 2 1-D arrays -> 1 1-D array
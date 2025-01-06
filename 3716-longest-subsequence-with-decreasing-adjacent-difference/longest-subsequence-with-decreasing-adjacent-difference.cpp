class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(301, vector<int>(301));
        for(int i = n-1; i >= 0; i--){
            int num = nums[i];
            for(int j = 1; j <= 300; j++){
                int d = abs(j-num);
                dp[num][d] = max(dp[num][d], dp[j][d]+1);
            }
            for(int j = 1; j <= 300; j++){
                dp[num][j] = max(dp[num][j], dp[num][j-1]);
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i <= 300; ++i){
            for (int j = 0; j <= 300; ++j){
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
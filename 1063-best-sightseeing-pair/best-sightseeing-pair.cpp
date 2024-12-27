class Solution {
public:
    int helper(int i, vector<vector<int>>&dp, vector<int>& values, int c){
        if(i==values.size()){
            if(c==2)
            return 0;
            else
            return -1e7;
        }

        if(dp[i][c]!=-1){
            return dp[i][c];
        }
        int ntake = helper(i+1,dp,values,c);
        int take = 0;
        if(c==0){
            take = values[i] + i + helper(i+1,dp,values,c+1);
        }
        if(c==1){
            take = values[i] - i + helper(i+1,dp,values,c+1);
        }
        dp[i][c] = max(ntake,take);
        return dp[i][c];
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return helper(0,dp,values,0);
    }
};
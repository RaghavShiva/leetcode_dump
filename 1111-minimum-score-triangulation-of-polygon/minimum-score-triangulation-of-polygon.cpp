class Solution {
public:
    int solve(int i, int j, vector<int>& v,  vector<vector<int>> &dp){
        if(i+2>j) return 0;
        if(i+2==j){
            return dp[i][j] = v[i]*v[i+1]*v[j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mn = 1e9;
        for(int k=i+1;k<j;k++){
            mn = min(mn, v[i]*v[k]*v[j]+solve(i,k,v,dp)+solve(k,j,v,dp));
        }
        dp[i][j] = mn;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(0,n-1,values,dp);
    }
};
class Solution {
public:
    long long solve(int i, vector<vector<int>>& q, vector<long long> &dp){
        if(i>=q.size()){
            return 0ll;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long nt = solve(i+1,q,dp);
        long long t = q[i][0] + solve(i+q[i][1]+1,q,dp);
        dp[i] = max(nt,t);
        return dp[i];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,-1);
        return solve(0,questions,dp);
    }
};
class Solution {
public:
    // long long solve(string &s, int ind, int i, int
    // j,vector<vector<vector<long long>>>&dp){
    //     if(ind==0){
    //         return 0;
    //     }
    //     if(dp[ind][i][j]!=-1){
    //         return dp[ind][i][j];
    //     }
    //     dp[ind][i][j]=solve(s,ind-1,i,)
    // }
    long long countSubstrings(string s) {
        int n = s.size();
        vector<vector<vector<long long>>> dp(
            n + 1, vector<vector<long long>>(10, vector<long long>(10, 0)));

        long long ans = 0;
        for (int ind = 1; ind <= n; ind++) {
            int curr = s[ind - 1] - '0';
            for (int i = 1; i < 10; i++) {
                for (int j = 0; j < i; j++) {
                    dp[ind][i][(j * 10 + curr) % i] += dp[ind - 1][i][j];
                }
                dp[ind][i][curr%i]++;
            }

            ans += dp[ind][curr][0];
        }
        return ans;
    }
};
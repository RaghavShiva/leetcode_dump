class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> dp(n, 0);
      
        dp[0] = (long long)skill[0] * mana[0];
        for (int i = 1; i < n; i++) 
            dp[i] = dp[i - 1] + (long long)skill[i] * mana[0];
        for (int j = 1; j < m; j++) {
            long long sum = dp[0], c = 0;
            for (int i = 1; i < n; i++) {
                c += (long long)skill[i - 1] * mana[j];
                sum = max(sum, dp[i] - c);
            }
            vector<long long> Ndp(n, 0);
            Ndp[0] = sum + (long long)skill[0] * mana[j];
            for (int i = 1; i < n; i++) 
                Ndp[i] = Ndp[i - 1] + (long long)skill[i] * mana[j];
            dp = move(Ndp);
        }
        return dp[n-1];
    }
};

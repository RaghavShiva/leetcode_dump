class Solution {
public:
    constexpr static long long M = 1e9 + 7;

    int countBalancedPermutations(string s) {
        int t = 0, n = s.size();
        vector<int> c(10);
        for (char x : s) {
            int d = x - '0';
            c[d]++;
            t += d;
        }
        if (t % 2) return 0;
        int g = t / 2, m = (n + 1) / 2;
        vector<vector<long long>> C(m + 1, vector<long long>(m + 1));
        vector<vector<long long>> dp(g + 1, vector<long long>(m + 1));
        for (int i = 0; i <= m; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
            }
        }
        dp[0][0] = 1;
        int ps = 0, ts = 0;
        for (int i = 0; i <= 9; i++) {
            ps += c[i];
            ts += i * c[i];
            for (int o = min(ps, m); o >= max(0, ps - (n - m)); o--) {
                int e = ps - o;
                for (int v = min(ts, g); v >= max(0, ts - g); v--) {
                    long long r = 0;
                    for (int j = max(0, c[i] - e); j <= min(c[i], o) && i * j <= v; j++) {
                        long long w = C[o][j] * C[e][c[i] - j] % M;
                        r = (r + w * dp[v - i * j][o - j] % M) % M;
                    }
                    dp[v][o] = r;
                }
            }
        }
        return dp[g][m];
    }
};

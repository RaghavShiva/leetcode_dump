class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        int m = edges.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        int mm = 1 << (n + 1);
        vector<vector<vector<bool>>> dp(
            mm, vector<vector<bool>>(n, vector<bool>(n, false)));
        int ans = 1;
        // for (int i = 0; i < n; i++) {
        //     dp[1 << i][i][i] = true;
        // }
        for (int i = 1; i < (1 << n); i++) {
            if (__builtin_popcount(i) == 1) {
                for (int j = 0; j < n; j++) {
                    if (i & (1 << j)) {
                        dp[i][j][j] = true;
                        for (int u : g[j]) {
                            if (label[u] == label[j]) {
                                int nmask = i | (1 << u);
                                dp[nmask][j][u] = true;
                            }
                        }
                        break;
                    }
                }
            }
        
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j))) {
                    for (int k = 0; k < n; k++) {
                        if ((i & (1 << k))) {
                            if (dp[i][j][k]) {
                                ans = max(ans, __builtin_popcount(i));

                                for (auto it : g[j]) {
                                    if (((1 << it) & i) == 0) {
                                        for (int itt : g[k]) {
                                            if(it!=itt){
                                                if (((1 << itt) & i) == 0) {
                                                    if (label[it] ==
                                                        label[itt]) {
                                                        dp[i | (1 << it) |
                                                           (1 << itt)][it]
                                                          [itt] = true;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
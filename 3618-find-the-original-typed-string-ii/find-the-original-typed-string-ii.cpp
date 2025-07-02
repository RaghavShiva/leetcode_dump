class Solution {
public:
    int possibleStringCount(string s, int k) {
        const int MOD = 1'000'000'007;
        int n = s.size(), runLength = 1;
        vector<int> blocks;

        for (int idx = 1; idx < n; ++idx) {
            if (s[idx] == s[idx - 1]) {
                ++runLength;
            } else {
                blocks.push_back(runLength);
                runLength = 1;
            }
        }
        blocks.push_back(runLength);

        long long totalWays = 1;
        for (int len : blocks) {
            totalWays = totalWays * len % MOD;
        }

        if (blocks.size() >= k) return totalWays;

        vector<int> dp(k), prefixSum(k, 1);
        dp[0] = 1;
        for (int b = 0; b < blocks.size(); ++b) {
            vector<int> nextDp(k);
            for (int j = 1; j < k; ++j) {
                nextDp[j] = prefixSum[j - 1];
                if (j - blocks[b] - 1 >= 0) {
                    nextDp[j] = (nextDp[j] - prefixSum[j - blocks[b] - 1] + MOD) % MOD;
                }
            }
            vector<int> nextPrefix(k);
            nextPrefix[0] = nextDp[0];
            for (int j = 1; j < k; ++j) {
                nextPrefix[j] = (nextPrefix[j - 1] + nextDp[j]) % MOD;
            }
            dp = move(nextDp);
            prefixSum = move(nextPrefix);
        }

        return (totalWays - prefixSum[k - 1] + MOD) % MOD;
    }
};

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        unordered_map<long, set<int>> rMap, cMap;
        vector<long> rSum(m, 0), cSum(n, 0), rPre(m, 0), cPre(n, 0);

        // Compute row & column sums and rowMap
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                long v = g[i][j];
                rMap[v].insert(i);
                rSum[i] += v;
                cSum[j] += v;
            }

        // Fill colMap
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cMap[g[i][j]].insert(j);

        // Prefix sums
        rPre[0] = rSum[0];
        cPre[0] = cSum[0];
        for (int i = 1; i < m; ++i) rPre[i] = rPre[i - 1] + rSum[i];
        for (int j = 1; j < n; ++j) cPre[j] = cPre[j - 1] + cSum[j];

        // Vertical partitions
        for (int j = 1; j < n; ++j) {
            long left = cPre[j - 1], right = cPre[n - 1] - left;
            if (left == right) return true;
            long diff = abs(left - right);
            if (left > right) {
                if (j == 1) {
                    if (g[0][0] == diff || g[m - 1][0] == diff) return true;
                } else if (cMap.count(diff)) {
                    auto it = cMap[diff].lower_bound(j);
                    if (it != cMap[diff].begin()) {
                        --it;
                        int pos = *it;
                        if (pos == j - 1 || pos == 0 || m != 1) return true;
                    }
                }
            } else {
                if (j == n - 1) {
                    if (g[0][j] == diff || g[m - 1][j] == diff) return true;
                } else if (cMap.count(diff)) {
                    auto it = cMap[diff].upper_bound(j - 1);
                    if (it != cMap[diff].end()) {
                        int pos = *it;
                        if (pos == j || pos == n - 1 || m != 1) return true;
                    }
                }
            }
        }

        // Horizontal partitions
        for (int i = 1; i < m; ++i) {
            long top = rPre[i - 1], bottom = rPre[m - 1] - top;
            if (top == bottom) return true;
            long diff = abs(top - bottom);
            if (top > bottom) {
                if (i == 1) {
                    if (g[0][0] == diff || g[0][n - 1] == diff) return true;
                } else if (rMap.count(diff)) {
                    auto it = rMap[diff].lower_bound(i);
                    if (it != rMap[diff].begin()) {
                        --it;
                        int pos = *it;
                        if (pos == i - 1 || pos == 0 || n != 1) return true;
                    }
                }
            } else {
                if (i == m - 1) {
                    if (g[i][0] == diff || g[i][n - 1] == diff) return true;
                } else if (rMap.count(diff)) {
                    auto it = rMap[diff].upper_bound(i - 1);
                    if (it != rMap[diff].end()) {
                        int pos = *it;
                        if (pos == i || pos == m - 1 || n != 1) return true;
                    }
                }
            }
        }

        return false;
    }
};

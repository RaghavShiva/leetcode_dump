class Solution {
public:
    int minMoves(vector<string>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));
        vector<vector<pair<int, int>>> tele(26);
        vector<bool> flag(26, false);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                char ch = grid[i][j];
                if (ch >= 'A' && ch <= 'Z')
                    tele[ch - 'A'].push_back({i, j});
            }

        vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
        cost[0][0] = 0;

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> heap;
        heap.push({0, 0, 0});

        while (!heap.empty()) {
            auto [val, i, j] = heap.top(); heap.pop();
            if (cost[i][j] < val) continue;
            if (i == rows - 1 && j == cols - 1) return val;

            char c = grid[i][j];
            if (c >= 'A' && c <= 'Z') {
                int idx = c - 'A';
                if (!flag[idx]) {
                    flag[idx] = true;
                    for (auto& [u, v] : tele[idx]) {
                        if (u == i && v == j) continue;
                        if (cost[u][v] > val) {
                            cost[u][v] = val;
                            heap.push({val, u, v});
                        }
                    }
                }
            }

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && nj >= 0 && ni < rows && nj < cols && grid[ni][nj] != '#') {
                    if (cost[ni][nj] > val + 1) {
                        cost[ni][nj] = val + 1;
                        heap.push({val + 1, ni, nj});
                    }
                }
            }
        }

        return -1;
    }
};

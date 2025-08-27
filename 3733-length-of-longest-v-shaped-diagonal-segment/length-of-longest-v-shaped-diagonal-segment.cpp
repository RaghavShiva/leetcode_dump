class Solution {
public:
    int m, n;
    int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    vector<vector<vector<vector<int>>>> memo;

    int dfs(vector<vector<int>>& grid, int x, int y, int dir, int turn, int target) {
        int nx = x + dirs[dir][0];
        int ny = y + dirs[dir][1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) return 0;
        if (memo[nx][ny][dir][turn] != -1) return memo[nx][ny][dir][turn];
        int res = dfs(grid, nx, ny, dir, turn, 2 - target);
        if (turn) res = max(res, dfs(grid, nx, ny, (dir + 1) % 4, 0, 2 - target));
        return memo[nx][ny][dir][turn] = res + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memo.assign(m, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(2, -1))));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        ans = max(ans, dfs(grid, i, j, d, 1, 2) + 1);
                    }
                }
            }
        }
        return ans;
    }
};

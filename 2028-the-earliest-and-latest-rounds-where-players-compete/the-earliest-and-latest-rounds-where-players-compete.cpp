class Solution {
private:
    int A[30][30][30], B[30][30][30];

    pair<int, int> solve(int n, int x, int y) {
        if (A[n][x][y]) return {A[n][x][y], B[n][x][y]};
        if (x + y == n + 1) return {1, 1};

        if (x + y > n + 1) {
            tie(A[n][x][y], B[n][x][y]) = solve(n, n + 1 - y, n + 1 - x);
            return {A[n][x][y], B[n][x][y]};
        }

        int lo = INT_MAX, hi = INT_MIN;
        int half = (n + 1) / 2;

        if (y <= half) {
            for (int a = 0; a < x; ++a) {
                for (int b = 0; b < y - x; ++b) {
                    auto [p, q] = solve(half, a + 1, a + b + 2);
                    lo = min(lo, p);
                    hi = max(hi, q);
                }
            }
        } else {
            int rem = n + 1 - y;
            int offset = (n - 2 * rem + 1) / 2;
            for (int a = 0; a < x; ++a) {
                for (int b = 0; b < rem - x; ++b) {
                    auto [p, q] = solve(half, a + 1, a + b + offset + 2);
                    lo = min(lo, p);
                    hi = max(hi, q);
                }
            }
        }

        A[n][x][y] = lo + 1;
        B[n][x][y] = hi + 1;
        return {A[n][x][y], B[n][x][y]};
    }

public:
    vector<int> earliestAndLatest(int n, int u, int v) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));

        if (u > v) swap(u, v);
        auto [res1, res2] = solve(n, u, v);
        return {res1, res2};
    }
};

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<vector<int>> L(n, vector<int>(3)), R(n, vector<int>(3));
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = 1 << (s[i] - 'a');
            if (!(b & x)) {
                c++;
                if (c <= k) b |= x;
                else {
                    a++;
                    b = x;
                    c = 1;
                }
            }
            L[i + 1][0] = a;
            L[i + 1][1] = b;
            L[i + 1][2] = c;
        }
        a = 0; b = 0; c = 0;
        for (int i = n - 1; i > 0; i--) {
            int x = 1 << (s[i] - 'a');
            if (!(b & x)) {
                c++;
                if (c <= k) b |= x;
                else {
                    a++;
                    b = x;
                    c = 1;
                }
            }
            R[i - 1][0] = a;
            R[i - 1][1] = b;
            R[i - 1][2] = c;
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int seg = L[i][0] + R[i][0] + 2;
            int m = L[i][1] | R[i][1], cnt = 0;
            while (m) {
                m &= (m - 1);
                cnt++;
            }
            if (L[i][2] == k && R[i][2] == k && cnt < 26) seg++;
            else if (min(cnt + 1, 26) <= k) seg--;
            mx = max(mx, seg);
        }
        return mx;
    }
};

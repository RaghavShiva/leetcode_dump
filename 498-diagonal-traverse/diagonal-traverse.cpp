class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
         if (mat.empty() || mat[0].empty()) return {};
        int n = mat.size(), m = mat[0].size();
        vector<int> res(n * m);
        vector<int> tmp;
        int k = 0;
        for (int d = 0; d < n + m - 1; d++) {
            tmp.clear();
            int r = d < m ? 0 : d - m + 1;
            int c = d < m ? d : m - 1;
            while (r < n && c >= 0) {
                tmp.push_back(mat[r][c]);
                r++; c--;
            }
            if (d % 2 == 0) reverse(tmp.begin(), tmp.end());
            for (int x : tmp) res[k++] = x;
        }
        return res;
    }
};
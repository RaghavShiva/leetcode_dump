class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        vector<int> v;
        int b = 1;
        while (n) {
            if (n % 2 == 1) {
                v.push_back(b);
            }
            n /= 2;
            b *= 2;
        }

        vector<int> ans;
        for (auto query : queries) {
            int cur = 1;
            for (int i = query[0]; i <= query[1]; ++i) {
                cur = (cur*1ll* v[i]) % mod;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
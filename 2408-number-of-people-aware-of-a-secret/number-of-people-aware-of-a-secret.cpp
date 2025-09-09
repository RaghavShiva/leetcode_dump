class Solution {
public:
    int peopleAwareOfSecret(int n, int d, int f) {
        const int MOD = 1e9 + 7;
        vector<long long> v(n + 1);
        v[1] = 1;

        long long cur = 0;
        for (int i = 2; i <= n; i++) {
            int add = i - d;
            int rem = i - f;

            if (add >= 1) cur = (cur + v[add]) % MOD;
            if (rem >= 1) cur = (cur - v[rem] + MOD) % MOD;

            v[i] = cur;
        }

        long long res = 0;
        for (int i = max(1, n - f + 1); i <= n; i++) {
            res = (res + v[i]) % MOD;
        }

        return (int)res;
    }
};

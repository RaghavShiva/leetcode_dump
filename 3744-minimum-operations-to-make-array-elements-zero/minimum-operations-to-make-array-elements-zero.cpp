class Solution {
public:
    long long prefix(long long n) {
        long long sum = 0, x = 1;
        int k = 1;
        while (x <= n) {
            long long r = min(n, x * 4 - 1);
            sum += k *1ll* (r - x + 1);
            x *= 4;
            k++;
        }
        return sum;
    }
    
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            int L = q[0], R = q[1];
            long long s = prefix(R) - prefix(L - 1);
            ans += (s + 1) / 2;
        }
        return ans;
    }
};

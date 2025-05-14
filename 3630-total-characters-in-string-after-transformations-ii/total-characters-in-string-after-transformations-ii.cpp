static constexpr int L = 26, mod = 1e9 + 7;

struct Mat {
    int a[L][L] = {};
    Mat operator*(const Mat& o) const {
        Mat r;
        for (int i = 0; i < L; ++i)
            for (int j = 0; j < L; ++j)
                for (int k = 0; k < L; ++k)
                    r.a[i][j] = (r.a[i][j] + 1LL * a[i][k] * o.a[k][j]) % mod;
        return r;
    }
};

Mat I() {
    Mat r;
    for (int i = 0; i < L; ++i) r.a[i][i] = 1;
    return r;
}

Mat quickmul(Mat x, int y) {
    Mat r = I();
    while (y) {
        if (y & 1) r = r * x;
        x = x * x;
        y >>= 1;
    }
    return r;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Mat T;
        for (int i = 0; i < L; ++i)
            for (int j = 1; j <= nums[i]; ++j)
                T.a[(i + j) % L][i] = 1;

        Mat res = quickmul(T, t);
        vector<int> freq(L);
        for (char c : s) ++freq[c - 'a'];

        int ans = 0;
        for (int i = 0; i < L; ++i)
            for (int j = 0; j < L; ++j)
                ans = (ans + 1LL * res.a[i][j] * freq[j]) % mod;

        return ans;
    }
};

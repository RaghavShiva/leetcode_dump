class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& a) {
        vector<int> st;
        for (int x : a) {
            while (!st.empty()) {
                int g = gcd(st.back(), x);
                if (g == 1) break;
                x = 1LL * st.back() / g * x;
                st.pop_back();
            }
            st.push_back(x);
        }
        return st;
    }

    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x;
    }
};

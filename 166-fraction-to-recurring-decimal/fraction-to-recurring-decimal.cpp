class Solution {
public:
     string fractionToDecimal(int a, int b) {
        if (a == 0) return "0";
        string res;
        if ((a < 0) ^ (b < 0)) res += "-";
        long long x = llabs((long long)a);
        long long y = llabs((long long)b);
        res += to_string(x / y);
        long long r = x % y;
        if (r == 0) return res;
        res += ".";
        unordered_map<long long, int> seen;
        while (r != 0) {
            if (seen.count(r)) {
                res.insert(seen[r], "(");
                res += ")";
                break;
            }
            seen[r] = res.size();
            r *= 10;
            res += to_string(r / y);
            r %= y;
        }
        return res;
    }
};
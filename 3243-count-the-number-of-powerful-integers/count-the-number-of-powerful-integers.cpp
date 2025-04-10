class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  const string& s) {
        string start_ = to_string(start - 1), finish_ = to_string(finish);
        return calculate(finish_, s, limit) - calculate(start_, s, limit);
    }

private:
    long long calculate(const string& x, const string& s, int limit) {
        if (x.length() < s.length()) {
            return 0;
        }
        if (x.length() == s.length()) {
            return x >= s ? 1 : 0;
        }

        string suffix = x.substr(x.length() - s.length());
        long long count = 0;
        int preLen = x.length() - s.length();

        for (int i = 0; i < preLen; i++) {
            int digit = x[i] - '0';
            if (limit < digit) {
                count += static_cast<long long>(pow(limit + 1, preLen - i));
                return count;
            }
            count += static_cast<long long>(digit) *
                     static_cast<long long>(pow(limit + 1, preLen - 1 - i));
        }

        if (suffix >= s) {
            count++;
        }
        return count;
    }
};

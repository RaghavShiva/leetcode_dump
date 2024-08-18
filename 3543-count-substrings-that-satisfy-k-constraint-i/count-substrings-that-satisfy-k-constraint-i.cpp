class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
    vector<int> countZero(n + 1, 0), countOne(n + 1, 0);
    int result = 0, j = 0;

    for (int i = 0; i < n; ++i) {
        countZero[i + 1] = countZero[i] + (s[i] == '0');
        countOne[i + 1] = countOne[i] + (s[i] == '1');

        while (countZero[i + 1] - countZero[j] > k && countOne[i + 1] - countOne[j] > k) {
            ++j;
        }

        result += i - j + 1;
    }

    return result;
    }
};
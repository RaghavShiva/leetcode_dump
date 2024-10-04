class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int i = static_cast<int>(ceil(log2(k))) - 1;
        int count = 0;

        while (k > 1) {
            if (k > (1LL << i)) {
                if (operations[i] == 1) {
                    count++;
                }
                k -= (1LL << i);
            }
            i--;
        }

        return 'a' + (count % 26);
    }
};

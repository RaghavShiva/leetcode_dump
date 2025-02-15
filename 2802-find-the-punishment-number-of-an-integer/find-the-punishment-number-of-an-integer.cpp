class Solution {
public:
    bool canPartition(string s, int t) {
        if (s == "" && t == 0) return true;

        if (t < 0) 
            return false;
        int n = s.size();
        for (int i=0;i<n;i++) {
            string l = s.substr(0, i + 1);
            string r = s.substr(i + 1);
            int leftNum = stoi(l);

            if (canPartition(r, t - leftNum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n;i++) {
            int j = i * i;

            if (canPartition(to_string(j), i)) {
                ans += j;
            }
        }
        return ans;
    }
};
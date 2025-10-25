class Solution {
public:
    bool solve(int i, int s, vector<int>& m, vector<int>& v){
        if(i < 0){
            return v[0] == s && v[1] == s && v[2] == s && v[3] == s;
        }

        for(int j = 0; j < 4; j++){
            if (v[j] + m[i] > s) continue;

            bool skip = false;
            for (int k = 0; k < j; ++k) {
                if (v[k] == v[j]) { skip = true; break; }
            }
            if (skip) continue;

            v[j] += m[i];
            if (solve(i - 1, s, m, v)) return true;
            v[j] -= m[i];

            if (v[j] == 0) break;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;

        int s = 0;
        for (int i = 0; i < n; i++) s += matchsticks[i];
        if (s % 4) return false;
        s = s / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks[0] > s) return false;

        vector<int> v(4, 0);
        return solve(n - 1, s, matchsticks, v);
    }
};

class Solution {
    int n;
    vector<vector<int>> dp;
    vector<vector<int>>* events;

    int dfs(int idx, int rem) {
        if (rem == 0 || idx == n) return 0;
        if (dp[idx][rem] != -1) return dp[idx][rem];

        int skip = dfs(idx + 1, rem);

        int nextIdx = upper_bound(events->begin(), events->end(), (*events)[idx][1],
            [](int val, const vector<int>& event) {
                return val < event[0];
            }) - events->begin();

        int take = (*events)[idx][2] + dfs(nextIdx, rem - 1);

        return dp[idx][rem] = max(skip, take);
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        n = events.size();
        dp.assign(n, vector<int>(k + 1, -1));
        this->events = &events;
        return dfs(0, k);
    }
};

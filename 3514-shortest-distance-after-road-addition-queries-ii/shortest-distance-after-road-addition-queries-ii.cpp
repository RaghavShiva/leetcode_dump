class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_map<int, int> map;
        
        for (int i = 0; i < n - 1; ++i) {
            map[i] = i + 1;
        }

        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0];
            int v = queries[i][1];

            if (!map.count(u) || map[u] >= v) {
                ans[i] = map.size();
                continue;
            }

            int j = map[u];
            while (j < v) {
                int next = map[j];
                map.erase(j);
                j = next;
            }
            map[u] = v;
            ans[i] = map.size();
        }

        return ans;
    }
};

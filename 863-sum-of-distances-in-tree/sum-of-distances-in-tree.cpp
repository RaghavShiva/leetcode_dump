class Solution {
public:
    vector<vector<int>> g;
    vector<int> counter, res;
    void dfs(int i, int p = -1) {
        for(auto u : g[i]) {
            if(u == p) continue;
            dfs(u, i);
            counter[i] += counter[u];
            res[i] += res[u] + counter[u];
        }
        counter[i] += 1;
    }

    void dfs2(int i, int n, int p = -1) {
        for(auto u : g[i]) {
            if(u == p) continue;
            res[u] = res[i] - counter[u] + (n - counter[u]);
            dfs2(u, n, i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(int i = 0; i < n - 1; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        res.resize(n);
        counter.resize(n);
        dfs(0);
        dfs2(0, n);
        return res;
    }
};

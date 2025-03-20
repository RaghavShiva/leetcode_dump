class Solution {
public:
    class DisjointSet {
        // reference :
        // https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/
        vector<int> rank, parent, size;

    public:
        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v)
                return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        int m = edges.size();
        vector<vector<pair<int, int>>> gr(n);
        DisjointSet ds(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (ds.findUPar(u) != ds.findUPar(v)) {
                ds.unionBySize(u, v);
            }
            gr[u].push_back({v, w});
            gr[v].push_back({u, w});
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int p = ds.findUPar(i);
            mp[p].push_back(i);
        }
        map<int, int> mpp;
        for (auto it : mp) {
            vector<int> v = it.second;
            int an = (1 << 20) - 1;

            for (int x : v) {
                for (auto p : gr[x]) {
                    an = an & p.second;
                }
            }
            mpp[it.first] = an;
        }
        vector<int> ans;
        for (auto q : query) {
            if (ds.findUPar(q[0]) != ds.findUPar(q[1])) {
                ans.push_back(-1);
            } else {
                ans.push_back(mpp[ds.findUPar(q[0])]);
            }
        }
        return ans;
    }
};
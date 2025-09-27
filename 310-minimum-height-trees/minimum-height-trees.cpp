class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> v(n, 0);
        if(n==1){
            return {0};
        }
        if(n==2){
            return {0,1};
        }
        for (int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            v[edges[i][0]]++;
            v[edges[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                q.push(i);
            }
        }
        int a = -1, b = -1;
        while (!q.empty()) {
            int s = q.size();
            if (s == 1) {
                return {q.front()};
            }

            for (int i = 0; i < s; i++) {
                int u = q.front();
                if (s == 2) {
                    if (i == 0) {
                        a = u;
                    }
                    if (i == 1) {
                        b = u;
                    }
                }
                q.pop();
                v[u]--;
                for (auto it : adj[u]) {
                    if (v[it]) {
                        v[it]--;
                    }
                    if (v[it] == 1) {
                        q.push(it);
                    }
                }
            }
        }
        return {a,b};
    }
};
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        int m = edges.size();
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<m;i++){
            g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        map<pair<int,int>,int> mp;
        vector<int> mn(n, maxMoves+1);
        mn[0] = 0;
        int ans = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > mn[u]) continue;
            ans++;

            for(auto it:g[u]){
                int v = it.first;
                int cnt = it.second;

                mp[{u,v}] = min(cnt, maxMoves - d);

                int nd = d + cnt + 1;
                if(nd < mn[v] && nd <= maxMoves){
                    mn[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        for(auto &edge:edges){
            int u=edge[0], v=edge[1], w=edge[2];
            int used1 = mp[{u,v}];
            int used2 = mp[{v,u}];
            ans += min(w, used1 + used2);
        }
        return ans;
    }
};

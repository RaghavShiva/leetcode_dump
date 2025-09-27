class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m = edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        vector<bool> vis(n,false);
        q.push(source);
        vis[source]=true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u==destination) return true;
            for(auto v:adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        return false;
    }
};
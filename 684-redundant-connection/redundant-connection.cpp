class Solution {
public:
    void dfs(int n, int i, int j, vector<vector<int>> &g,  vector<int> &vis){
        vis[n]=1;
        for(int x:g[n]){
            if(!vis[x] &&!( (n==i && x==j)||(n==j && x==i))){
                dfs(x,i,j,g,vis);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>g(n+1);
        for(int i = 0; i < n; i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = n-1; i >= 0; i--){
            vector<int> vis(n+1,0);
            bool f = true;
            dfs(1,edges[i][0],edges[i][1],g,vis);
            for(int i = 1; i <= n; i++){
                if(vis[i]){
                    continue;
                }
                f=false;
                break;
            }
            if(f){
                return edges[i];
            }

        }
        return {};
    }
};
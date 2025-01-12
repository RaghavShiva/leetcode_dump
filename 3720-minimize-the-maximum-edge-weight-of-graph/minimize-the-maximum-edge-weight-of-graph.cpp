class Solution {
public:
    void dfs(int m, vector<vector<pair<int,int>>> &g, vector<bool> &vis, int i){
        vis[i] = true;
        for(auto it : g[i]){
            if(!vis[it.first] && it.second<=m){
                dfs(m,g,vis,it.first);
            }
        }
    }
    bool solve(int m, vector<vector<pair<int,int>>> &g, int n){
        vector<bool> vis(n,false);
        dfs(m,g,vis,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> g(n);
        int h = 0, l = 0, m = 0;
        for(int i = 0; i < edges.size(); i++){
            g[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            h = max(h, edges[i][2]);
        }
        int ans = -1;
        while(l<=h){
            m = (l+h)/2;
            if(solve(m,g,n)){
                ans = m;
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};
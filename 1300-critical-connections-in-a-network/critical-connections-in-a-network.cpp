class Solution {
public: 
    void dfs(int n, int t, int p, vector<bool> &vis, vector<int> &in, vector<int> &low, vector<vector<int>> &g, vector<vector<int>> &ans){
        vis[n] = true;
        t++;
        in[n] = t;
        low[n] = t;
        for(auto it:g[n]){
            if(it==p) continue;
            if(!vis[it]){
                dfs(it,t,n,vis,in,low,g,ans);
                low[n] = min(low[n],low[it]);
                if(in[n]<low[it]){
                    ans.push_back({n,it});
                }
            }
            else{
                low[n] = min(low[n],in[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        vector<vector<int>> g(n);
        vector<int> in(n), low(n);
        vector<bool> vis(n,false);
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }

        dfs(0,0,-1,vis,in,low,g,ans);
        
        return ans;
    }
};
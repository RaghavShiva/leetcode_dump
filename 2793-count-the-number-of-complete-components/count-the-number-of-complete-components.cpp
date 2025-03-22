class Solution {
public:
    void dfs(int n,vector<bool>&vis,vector<vector<int>>&g,vector<int>&v){
        vis[n]=true;
        v.push_back(n);
        for(auto it:g[n]){
            if(!vis[it]){
                dfs(it,vis,g,v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>v;
        vector<vector<int>>g(n);
        int m = edges.size();
        for(int i=0;i<m;i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>t;
                dfs(i,vis,g,t);
                v.push_back(t);
            }
        }
        int ans = 0;
        for(auto vv:v){
            int x = vv.size();
            int s=0;
            for(auto it:vv){
                s+=g[it].size();
            }
            if(s==x*(x-1)){
                ans++;
            }
        }
        return ans;
    }
};
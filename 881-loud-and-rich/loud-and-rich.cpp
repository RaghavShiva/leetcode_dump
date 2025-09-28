class Solution {
public:
    void dfs(int i, int &y,vector<vector<int>> &g,vector<bool> &vis, int &t, vector<int> &q){
        vis[i]=true;
        if(q[i]<t){
            t=q[i];
            y=i;
        }
        for(auto it:g[i]){
            if(!vis[it])
            dfs(it,y,g,vis,t,q);
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int m = richer.size();
        int n = quiet.size();
        if(n==1){
            return {0};
        }
        vector<int> ans(n,0);
        vector<vector<int>>g(n);
        for(int i=0;i<m;i++){
            g[richer[i][1]].push_back(richer[i][0]);
        }
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            int t = n;
            int y=-1;
            dfs(i,y,g,vis,t,quiet);
            ans[i]=y;
        }
        return ans;
    }
};
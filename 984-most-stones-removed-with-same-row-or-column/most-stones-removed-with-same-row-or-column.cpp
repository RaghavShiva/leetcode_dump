class Solution {
public:
    void dfs(int n, vector<bool>&v, vector<vector<int>> &g){
        v[n]=true;
        for(auto it:g[n]){
            if(v[it]) continue;
            dfs(it,v,g);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> g(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            ans++;
            dfs(i,vis,g);
        }
        ans=n-ans;
        return ans;
    }
};
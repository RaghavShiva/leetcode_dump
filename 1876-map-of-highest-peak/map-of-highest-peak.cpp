class Solution {
public:
void solve(queue<pair<int,int>>&q,int x,int y,vector<vector<int>>&adj,int n,int m,int t,vector<vector<int>>& ans){
    if(x>0 && adj[x-1][y]==1){
        adj[x-1][y]=0;
        ans[x-1][y]=t;
        q.push({x-1,y});
    }
    if(y<(m-1) && adj[x][y+1]==1){
        adj[x][y+1]=0;
        ans[x][y+1]=t;
        q.push({x,y+1});
    }
    if(x<(n-1) && adj[x+1][y]==1){
        adj[x+1][y]=0;
        ans[x+1][y]=t;
        q.push({x+1,y});
    }
    if(y>0 && adj[x][y-1]==1){
        adj[x][y-1]=0;
        ans[x][y-1]=t;
        q.push({x,y-1});
    }
}
    vector<vector<int>> bfs(vector<vector<int>>&adj,int n,int m){
     queue<pair<int,int>>q;
     int x=0;
     vector<int>v(m);
     vector<vector<int>>ans(n,v);
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(adj[i][j]==0){
                 q.push({i,j});
                 ans[i][j]=0;
             }
         }
     }
    while(!q.empty()){
        int c=q.size();
         x++;
         for (int i = 0; i < c; i++) {
             auto it = q.front();
             q.pop();
             solve(q, it.first, it.second, adj, n, m, x, ans);
         }
    }

    return ans;
}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n,1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j]==1){
                    height[i][j] = 0;
                }
            }
        }
        return bfs(height,m,n);
    }
};
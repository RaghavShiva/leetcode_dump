class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis, int m, int n){
        vis[i][j]=1;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        int s = grid[i][j];
        for(int k = 0; k < 4; k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni>=0 && ni < m && nj>=0 && nj < n && !vis[ni][nj] && grid[ni][nj]>0){
                s += dfs(grid, ni, nj, vis, m, n);
            }
        }
        return s;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]>0 && !vis[i][j]){
                 ans = max(ans, dfs(grid,i,j,vis,m,n));   
                }
            }  
        }
        return ans;
    }
};
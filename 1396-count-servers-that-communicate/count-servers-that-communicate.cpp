class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==1){
                int c = 0;
                for(int r = 0; r < m; r++){
                    if(grid[r][j]==1){
                        c++;
                    }
                }
                for(int r = 0; r < n; r++){
                    if(grid[i][r]==1){
                        c++;
                    }
                }
                
                if(c>2){
                    ans++;
                }
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            int c = -1;
            for(int j = 0; j < n; j++){
                if(c >= grid[j][i]){
                    ans += c + 1 -grid[j][i];
                    grid[j][i] = c + 1;
                }
                c = grid[j][i];
            }   
        }
        return ans;
    }
};
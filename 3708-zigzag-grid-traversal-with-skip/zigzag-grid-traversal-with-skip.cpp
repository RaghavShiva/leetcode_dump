class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                if(i%2){
                    if(c%2==0){
                        ans.push_back(grid[i][m-1-j]);
                    }
                }
                else {
                    if(c%2==0){
                        ans.push_back(grid[i][j]);
                    }
                }
                c++;
            }
        }
        return ans;
    }
};
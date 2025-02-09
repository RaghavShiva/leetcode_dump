class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>v(2*n-1);
        
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                v[j-i+n-1].push_back(grid[i][j]);
            }
        }
        for(int i=0;i<n*2-1;i++){
            if(i<n)
            sort(v[i].begin(),v[i].end());
            else
            sort(v[i].rbegin(),v[i].rend());
        }
        int a=0;
        int b=n*n-1;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = v[j-i+n-1].back();
                v[j-i+n-1].pop_back();
                
            }
        }
        return grid;
    }
};
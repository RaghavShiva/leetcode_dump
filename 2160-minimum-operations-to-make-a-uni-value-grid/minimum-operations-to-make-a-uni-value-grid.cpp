class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        vector<int>v;
        int m = grid[0].size();
        int c = grid[0][0]%x;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c!=grid[i][j]%x){
                    return -1;
                }
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        n=n*m;
        c = v[n/2];
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += abs(c-v[i])/x;
        }
        return ans;
    }
};
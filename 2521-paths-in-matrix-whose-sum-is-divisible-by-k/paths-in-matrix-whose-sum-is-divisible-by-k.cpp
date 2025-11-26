class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
       int m = grid.size();
       int n = grid[0].size();
       int mod = 1e9+7;
       vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int>(k,0)));
    // base case
       dp[m-1][n-1][grid[m-1][n-1]%k]=1;

       for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i+1<m){
            for(int s=0;s<k;s++){
                // for left ops
                dp[i][j][(grid[i][j]+s)%k] = (dp[i+1][j][s]+dp[i][j][(grid[i][j]+s)%k])%mod;
                }
            }
                if(j+1<n){
                    // for up ops
                    for(int s=0;s<k;s++){
                    dp[i][j][(grid[i][j]+s)%k] = (dp[i][j+1][s]+dp[i][j][(grid[i][j]+s)%k])%mod;
                }
                }  
        }
       } 
    return dp[0][0][0];
    }
};
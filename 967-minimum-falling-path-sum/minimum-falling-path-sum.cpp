class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e9;
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=1e9,ldg=1e9,rdg=1e9;
                up =dp[i-1][j];
                if(j>0){
                    ldg = dp[i-1][j-1];
                }
                if(j<n-1){
                    rdg = dp[i-1][j+1];
                }
                dp[i][j] =  matrix[i][j]+min({up,ldg,rdg});
            }   
        }
        for(int j=0;j<n;j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};
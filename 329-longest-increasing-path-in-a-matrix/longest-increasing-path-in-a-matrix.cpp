class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& mat, vector<vector<int>> &dp){
        vector<int> dr = {-1,0,0,1};
        vector<int> dc = {0,-1,1,0};
        int v=1;
        for(int k=0;k<4;k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc]>mat[i][j]){
                if(dp[nr][nc]==0){
                    v = max(v,1+dfs(nr,nc,m,n,mat,dp));
                }
                else{
                    v = max(v,1+dp[nr][nc]);
                }
            }
        }
        dp[i][j] = v;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==0){
                    ans=max(ans,dfs(i,j,m,n,matrix,dp));
                }
            }
        }
        return ans;
    }
};
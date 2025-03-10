class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)
        return 1;
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = solve(i-1,j,dp);
        int right = solve(i,j-1,dp);
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<int>cur(n+1,0);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1){
                    cur[j]=1;
                }
                else{
                    cur[j]+=cur[j-1];
                }
            }
        }
        return cur[n];
    }
};
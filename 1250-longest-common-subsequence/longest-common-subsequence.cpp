class Solution {
public:
    int solve(int i,int j,string &s1,string &s2, vector<vector<int>>&dp){
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s1[i]==s2[j])
        return dp[i][j]=1+solve(i-1,j-1,s1,s2,dp);
       
        return dp[i][j]= max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int>dp(m+1,0),prev(m+1,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[j]=1+prev[j-1];
                }else{
                    dp[j]=max(prev[j],dp[j-1]);
                }
            }
            prev=dp;
        }
        return dp[m];
    }
};
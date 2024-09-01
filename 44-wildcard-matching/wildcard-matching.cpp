class Solution {
public:
    int solve(int i,int j,string &s, string &p,vector<vector<int>>&dp){
        if(i==s.size() && j==p.size())
        return 1;
        if(j==p.size())
        return 0;
        if(i==s.size()){
            for(int k=j;k<p.size();k++){
                if(p[k]!='*'){
                    return 0;
                }
            }
            return 1;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];

        if(p[j]=='*'){
            return dp[i][j]=solve(i+1,j+1,s,p,dp)|solve(i+1,j,s,p,dp)|solve(i,j+1,s,p,dp);
        }
        if(p[j]=='?' || s[i]==p[j]){
            return dp[i][j]=solve(i+1,j+1,s,p,dp);
        }
        
        return dp[i][j]=0;

    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       
        return solve(0,0,s,p,dp);
    }
};
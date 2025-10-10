class Solution {
public:
    bool solve(int i, int n, int d, vector<int> &dp){
        if(dp[i]!=-1) return dp[i];
        if(d<=0) return false;
        for(int j=0;j<n;j++){
            if(!(i&(1<<j)) && !solve(i|(1<<j),n,d-(j+1),dp)){
                dp[i]=1;
                return true;
            }
        }
        dp[i]=0;
        return false;
    }
    bool canIWin(int n, int d) {
        if(d<=1) return true;
        int s = n*(n+1)/2;
        if(s<d) return false;
        if(s==d) return n%2;

        vector<int>dp(1<<n,-1);
        return solve(0,n,d,dp);

    }
};
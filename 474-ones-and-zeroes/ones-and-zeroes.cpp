class Solution {
public:
    pair<int,int> count(string &s){
        int n = s.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') c++;
        }
        pair<int,int> ans;
        ans = {c,n-c};
        return ans;
    }

    int solve(vector<pair<int,int>> &v, int i, int m, int n, vector<vector<vector<int>>> &dp){
        if(i<0){
            return 0;
        }
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int t=0,nt;
        if(v[i].first<=m && v[i].second<=n){
            t = 1+solve(v,i-1,m-v[i].first,n-v[i].second,dp);
        }
        nt = solve(v,i-1,m,n,dp);
        return dp[i][m][n] = max(t,nt);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<pair<int,int>> v(s);
        for(int i=0;i<s;i++){
            v[i] = count(strs[i]);
        }

        vector<vector<vector<int>>> dp(s,vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return solve(v,s-1,m,n,dp);
    }
};
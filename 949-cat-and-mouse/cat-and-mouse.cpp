class Solution {
public:
    int solve(int m, int c, int mv, vector<vector<int>>& g,vector<vector<vector<int>>> &dp){
        if(mv>g.size()*5) return 0;
        if(m==c) return 2;
        if(m==0) return 1;
        if(dp[m][c][mv]!=-1){
            return dp[m][c][mv];
        }
        bool dr = false;
        if(mv%2==0){
            for(auto it:g[m]){
                int ans = solve(it,c,mv+1,g,dp);
                if(ans==1){
                    return dp[m][c][mv]=1;
                }
                if(ans==0){
                    dr = true;
                }
            }
            if(dr){
                return dp[m][c][mv]=0;
            }
            return dp[m][c][mv]=2;
        }
        else{
            for(auto it:g[c]){
                if(it==0) continue;
                int ans = solve(m,it,mv+1,g,dp);
                if(ans==2){
                    return dp[m][c][mv]=2;
                }
                if(ans==0){
                    dr = true;
                }
            }
            if(dr){
                return dp[m][c][mv]=0;
            }
            return dp[m][c][mv]=1;
        }
        return 0;
    }
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n, vector<int>(5*n+5,-1)));
        return solve(1,2,0,graph,dp);
    }
};
class Solution {
public:
    int solve(int m, vector<vector<int>> &g, vector<int> &in, vector<int> &s, int n, vector<int> &dp){
        if(m==((1<<n)-1)) return 0;
        if(dp[m]!=-1){
            return dp[m];
        }

        int pos = __builtin_popcount(m);
        pos++;
        int ans=0;

        for(int i=0;i<n;i++){
            if(!(m&(1<<i)) && in[i]==0){
                int nm = m|(1<<i);
                for(auto it:g[i]){
                    in[it]--;
                }
                ans = max(ans, pos*s[i]+solve(nm,g,in,s,n,dp));
                for(auto it:g[i]){
                    in[it]++;
                }
            }
        }
        return dp[m] = ans;
    }
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        int m = edges.size();
        vector<vector<int>> g(n);
        vector<int> in(n,0);

        for(int i=0;i<m;i++){
        g[edges[i][0]].push_back(edges[i][1]);
        in[edges[i][1]]++;
        }

        int ms = 1<<n;
        vector<int> dp(ms,-1);
        return solve(0,g,in,score,n,dp);
    }
};
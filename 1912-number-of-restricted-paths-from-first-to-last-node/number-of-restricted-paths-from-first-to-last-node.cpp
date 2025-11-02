class Solution {
    int mod = 1e9+7;
public:
    int solve_dfs(vector<vector<int>>&g,int s, int d, vector<int>&dp){
        if(s==d) return 1;
        if(dp[s]!=-1) return dp[s];
        int c=0;
        for(auto it:g[s]){
            c = (c + solve_dfs(g,it,d,dp))%mod;
        }
        dp[s] = c;
        return c;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<pair<int,int>>>g(n+1);
        for(int i=0;i<m;i++){
            g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<long long>dist(n+1,1e10);
        priority_queue<pair<int,long long>,vector<pair<int,long long>>,greater<pair<int,long long>>>q;
        q.push({0,n});
        dist[n]=0;
        while(!q.empty()){
            auto[d,nd] = q.top();
            q.pop();
            for(auto it:g[nd]){
                if(d+it.second<dist[it.first]){
                    dist[it.first] = d+it.second;
                    q.push({dist[it.first],it.first});
                }
            }
        }
        
        vector<vector<int>>gg(n+1);
        for(int i=0;i<m;i++){
            if(dist[edges[i][0]]>dist[edges[i][1]]){
                gg[edges[i][0]].push_back(edges[i][1]);
            }
            if(dist[edges[i][0]]<dist[edges[i][1]]){
                gg[edges[i][1]].push_back(edges[i][0]);
            }
        }
        vector<int>dp(n+1,-1);
        return solve_dfs(gg,1,n,dp);
    }
};
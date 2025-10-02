class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = 1<<n;
        int ans=0;
        queue<pair<int,int>>q;
        vector<vector<bool>> dp(m, vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[1<<i][i]=true;
            q.push({i,(1<<i)});
        }
        while (!q.empty()) {
            int s = q.size(); 
            while (s--) {
                pair<int, int> p = q.front();
                q.pop();
                int node = p.first;
                int mask = p.second;
                if (mask == m-1) {
                    return ans;
                }

                for (int it : graph[node]) {
                    int n_mask = mask | (1 << it); 
                    if (!dp[n_mask][it]) {
                        dp[n_mask][it] = true;
                        q.push({it, n_mask});
                    }
                }
            }
            ans++; 
        }
        
        return -1;
    }
};
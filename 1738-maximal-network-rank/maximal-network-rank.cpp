class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>>g(n);
        int m = roads.size();
        for(int i=0;i<m;i++){
            g[roads[i][0]].insert(roads[i][1]);
            g[roads[i][1]].insert(roads[i][0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int c=0;
                if(g[i].find(j)!=g[i].end()){
                    c--;
                }
                c += g[i].size()+g[j].size();
                ans = max(ans,c);
            }
        }
        return ans;
    }
};
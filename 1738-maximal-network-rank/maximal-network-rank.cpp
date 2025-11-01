class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>g(n);
        int m = roads.size();
        for(int i=0;i<m;i++){
            g[roads[i][0]].push_back(roads[i][1]);
            g[roads[i][1]].push_back(roads[i][0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int c=0;
                for(auto it:g[i]){
                    if(it==j) c--;
                }
                c += g[i].size()+g[j].size();
                ans = max(ans,c);
            }
        }
        return ans;
    }
};
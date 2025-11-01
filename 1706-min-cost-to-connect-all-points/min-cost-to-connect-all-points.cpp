class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>>g(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int c = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                g[i].push_back({j,c});
                g[j].push_back({i,c});
            }
        }
        int ans = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        pq.push({0,0});
        vector<bool>vis(n,false);

        while(!pq.empty()){
            auto[c,nd] = pq.top();
            pq.pop();
            
            if(vis[nd]) continue;
            ans+=c;
            vis[nd]=true;
            
            for(auto it:g[nd]){
                if(!vis[it.first]){
                    pq.push({it.second,it.first});
                }
            }
        }
        return ans;
    }
};
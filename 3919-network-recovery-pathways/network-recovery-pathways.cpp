class Solution {
public:
    bool solve(int m, vector<vector<pair<int,int>>> &g, long long k, vector<bool>& on, int n){
        priority_queue<pair<long long, int>,vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        vector<long long> v(n,-1);
        q.push({0,0});
        v[0]=0;
        while(!q.empty()){
            int s = q.top().second;
            long long c = q.top().first;
            q.pop();
            if (v[s] != -1 && c > v[s]) {
                continue;
            }
            if(s==n-1){
                return true;
            }
            for(auto it:g[s]){
                int nd = it.first;
                int ct = it.second;
                if(ct>=m && (v[nd]==-1 || v[nd]>c+ct) && c+ct<=k && on[nd]){
                    q.push({c+ct,nd});
                    v[nd] = c+ct;
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int m = edges.size();
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<m;i++){
            g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        int r = 1e9+1, l=0;
        while(l<=r){
            int m = l+(r-l)/2;
            if(solve(m,g,k,online,n)){
                l = m+1;
            }
            else{
                r=m-1;
            }
        }
        return r;
    }
};
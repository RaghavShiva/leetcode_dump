class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
          vector<vector<pair<long long,long long>>>adj(n);
    vector<long long>v(n,1e17);
  
    for(int i=0;i<edges.size();i++){
    adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
}
vector<long long>w(n,1);
w[0]=1;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,0});
    v[0]=0;
 int mod=(int)(1e9+7);
    while(!pq.empty()){
        long long d=pq.top().first;
        long long x=pq.top().second;
        pq.pop();
        for(auto it:adj[x]){
            if((d+it.second)<v[it.first]){
                w[it.first]=w[x];
                v[it.first]=d+it.second;
                pq.push({d+it.second,it.first});
            }
            else if((d+it.second)==v[it.first])
            w[it.first]=(w[it.first]%mod+w[x]%mod)%mod;
        }
    }
   return w[n-1];
    }
};
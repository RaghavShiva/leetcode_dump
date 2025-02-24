class Solution {
public:
    bool dfs(vector<int>&vis,vector<vector<int>>&g,int n,map<int,int>&time,int t){
        vis[n]=1;
        time[n]=t;
        if(n==0)
        return true;
        for(auto it:g[n]){
            if(!vis[it]){
                if(dfs(vis,g,it,time,t+1))
                return true;
            }
        }
        time.erase(n);
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int ans=-1e9;
        int n = edges.size();
        vector<vector<int>> g(n+1);
        for(int i=0;i<n;i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n+1,0);
        map<int,int>time;
        dfs(vis,g,bob,time,0);
        // for(auto it:time){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
        fill(vis.begin(), vis.end(), 0);
        queue<vector<int>>q;
        q.push({0,0,0});
        while(!q.empty()){
            auto it = q.front();
            int nd = it[0];
            int t = it[1];
            int c = it[2];
            vis[nd]=1;
            q.pop();
            if(time.find(nd)==time.end() || time[nd]>t){
                c+=amount[nd];
            }
            else if(time[nd]==t){
                c+=(amount[nd]/2);
            }
            if(g[nd].size()==1 && nd!=0){
                ans = max(ans,c);
            }
            
            for(auto i:g[nd]){
                if(!vis[i]){
                    q.push({i,t+1,c});
                }
            }
            // cout<<c<<' ';
        }
        return ans;
    }
};
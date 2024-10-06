class Solution {
public:
    void bfs(int k,vector<int>&vis, vector<vector<int>>&adj){
        queue<int>q;
        vis[k]=1;
        q.push(k);
        while(!q.empty()){
        int t=q.front();
        q.pop();
        
        for(int j=0;j<adj[t].size();j++){
            if(vis[adj[t][j]]==0){
               vis[adj[t][j]]=1;
               q.push(adj[t][j]);
            }
            
        }

    }

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
       vector<vector<int>>adj(n);
       for(auto p:invocations){
        adj[p[0]].push_back(p[1]);
       } 
       vector<int>vis(n,0);
       bfs(k,vis,adj);
       set<int>s;
       for(auto p:invocations){
        if(!vis[p[0]])
        s.insert(p[1]);
       }
       bool f=false;
        for(int i=0;i<n;i++){
        if(vis[i]){
            if(s.find(i)!=s.end()){
                f=true;
                break;
            }
        }
        }
        vector<int>ans;
        if(!f){
           for(int i=0;i<n;i++){
        if(!vis[i])
        ans.push_back(i);
       } 

        }
        else{
            for(int i=0;i<n;i++){
        ans.push_back(i);
       } 
        }
        
       return ans;
    }
};
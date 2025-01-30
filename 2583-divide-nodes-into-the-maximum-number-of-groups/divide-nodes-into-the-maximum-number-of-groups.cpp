class Solution {
public:
    void dfs(int i, vector<vector<int>> &g, vector<int> &vis, vector<int> &v){
        vis[i]=1;
        v.push_back(i);
        for(int n:g[i]){
            if(!vis[n]){
                dfs(n,g,vis,v);
            }
        }
    }
    int bfs(int i, vector<vector<int>> &g, int n){
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(i);
        vis[i]=1;
        int l = 0;
        while(!q.empty()){
            int s = q.size();
            l++;
            for(int a = 0; a < s; a++){
                int node = q.front();
                q.pop();
                for(auto it:g[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
        return l;
    }
    bool hasOddCycle(int n, vector<vector<int>> &g, vector<int> &v) {
        vector<int> color(n+1, -1); 
        int s = v.size();
        for(int i = 0; i < s; i++){
            if (color[v[i]] == -1) { 
                queue<int> q;
                q.push(v[i]);
                color[v[i]] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : g[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node]; 
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>>g(n+1);
        for(int i = 0; i < m; i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n+1,0);
        vector<vector<int>> comp;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                vector<int>v;
                dfs(i,g,vis,v);
                comp.push_back(v);
            }
        }
        for(auto v:comp){
            if(hasOddCycle(n,g,v)){
                return -1;
            }
        }

        int ans = 0;
        for(auto v:comp){
            int j = v.size();
            // cout<<j<<' ';
            int t = 0;
            for(int i = 0; i < j; i++){
                t = max(t,bfs(v[i],g,n));
            }
            ans += t;
        }
        return ans;
    }
};
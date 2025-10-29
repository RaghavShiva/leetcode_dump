class Solution {
public:
    vector<int> bfs(int n, vector<vector<int>>& g){
        vector<bool>vis(n,false);
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int gd = q.front();
                    q.pop();
                    vector<bool> col(4,false);
                    for(auto it:g[gd]){
                        if(ans[it]!=-1){
                            col[ans[it]-1]=true;
                        }
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=true;
                        }
                    }
                    for(int j=0;j<4;j++){
                        if(!col[j]){
                            ans[gd] = j+1;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        int m = paths.size();
        vector<vector<int>> g(n);
        for(int i=0;i<m;i++){
            g[paths[i][0]-1].push_back(paths[i][1]-1);
            g[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        return bfs(n,g);
    }
};
class Solution {
public:
    void solve(vector<vector<int>>& h, bool f, vector<int> &v){
        int m = h.size();
        int n = h[0].size();
        vector<bool> vis(m*n,false);
        queue<int>q;
        vector<int> dr = {-1,0,0,1};
        vector<int> dc = {0,1,-1,0};
        if(f){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0 || j==0){
                        vis[i*n+j] =true;
                        q.push(i*n+j);
                        v[i*n+j]++;
                    }
                }
            }
        }
        else{
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==m-1 || j==n-1){
                        vis[i*n+j] =true;
                        q.push(i*n+j);
                        v[i*n+j]++;
                    }
                }
            }
        }
        while(!q.empty()){
            int cl = q.front();
            q.pop();
            int r = cl/n;
            int c = cl%n;
            for(int i=0;i<4;i++){
                int nr = dr[i] + r;
                int nc = dc[i]+c;
                int ncl = nr*n+nc;
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[ncl] && h[r][c]<=h[nr][nc]){
                    q.push(ncl);
                    vis[ncl] = true;
                    v[ncl]++;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<int> v(m*n,0);
        vector<vector<int>> ans;
        solve(heights,true,v);
        solve(heights,false,v);
        for(int i=0;i<m*n;i++){
            if(v[i]==2){
                ans.push_back({i/n,i%n});
            }
        }
        return ans;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(n*n,n*n);
        vector<int> dr = {-1,0,0,1};
        vector<int> dc= {0,1,-1,0};

        queue<pair<int,int>>q;
        q.push({0,grid[0][0]});
        ans[0]=grid[0][0];

        while(!q.empty()){
            int cl = q.front().first;
            int t = q.front().second;
            q.pop();
            if(ans[cl]<t) continue;
            int r = cl/n;
            int c = cl%n;
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                int ncl = nr*n+nc;
                
                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int nt = max(t,grid[nr][nc]);
                    if(ans[ncl]>nt){
                        ans[ncl] = nt;
                    q.push({ncl,nt});
                    }
                }
            }
        }
        return ans[n*n-1];
    }
};
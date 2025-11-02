class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>v(m,vector<int>(n,0));
        for(auto it:walls){
            v[it[0]][it[1]] = 2;
        }
        for(auto it:guards){
            v[it[0]][it[1]] = -1;
        }
        for(auto it:guards){
            int x = it[0];
            int y = it[1];
            for(int i=x+1;i<m;i++){
                if(v[i][y]==0){
                    v[i][y]=1;
                }
                if(v[i][y]==2||v[i][y]==-1){
                    break;
                }
            }
            for(int i=x-1;i>=0;i--){
                if(v[i][y]==0){
                    v[i][y]=1;
                }
                if(v[i][y]==2||v[i][y]==-1){
                    break;
                }
            }
            for(int i=y+1;i<n;i++){
                if(v[x][i]==0){
                    v[x][i]=1;
                }
                if(v[x][i]==2||v[x][i]==-1){
                    break;
                }
            }
            for(int i=y-1;i>=0;i--){
                if(v[x][i]==0){
                    v[x][i]=1;
                }
                if(v[x][i]==2||v[x][i]==-1){
                    break;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0) ans++;
            }
        }
        return ans;
    }
};
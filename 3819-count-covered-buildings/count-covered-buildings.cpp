class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> mpx(n+1,1e9),mpy(n+1,1e9);
        vector<int> mxx(n+1,0), mxy(n+1,0);
        int m = buildings.size();
        int ans = 0;
        for(int i=0;i<m;i++){
            mpx[buildings[i][0]] = min(mpx[buildings[i][0]],buildings[i][1]);
            mxx[buildings[i][0]] = max(mxx[buildings[i][0]],buildings[i][1]);
            mpy[buildings[i][1]] = min(mpy[buildings[i][1]],buildings[i][0]);
            mxy[buildings[i][1]] = max(mxy[buildings[i][1]],buildings[i][0]);
        }

        for(int i=0;i<m;i++){
            int x = buildings[i][0];
            int y = buildings[i][1];
            if(x>mpy[y] && x<mxy[y] && y>mpx[x] && y<mxx[x]){
                ans++;
            }
        }
        return ans;

    }
};
class Solution {
public:
    void dfs(int s, vector<vector<int>>& r, vector<bool> &vis){
        vis[s] = true;
        for(auto it:r[s]){
            if(!vis[it]){
                dfs(it,r,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        dfs(0,rooms,vis);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
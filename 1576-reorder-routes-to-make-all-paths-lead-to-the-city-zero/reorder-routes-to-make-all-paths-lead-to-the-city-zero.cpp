class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>g1(n),g2(n);
        for(int i=0;i<n-1;i++){
            g1[connections[i][1]].push_back(connections[i][0]);
            g2[connections[i][0]].push_back(connections[i][1]);
        }
        queue<int>q;
        vector<bool> vis(n,false);
        vis[0]=true;
        q.push(0);
        int ans = 0;
        while(!q.empty()){
            int c = q.front();
            q.pop();
            for(auto it:g1[c]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                }
            }
            for(auto it:g2[c]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                    ans++;
                }
            }
        }
        return ans;
    }
};
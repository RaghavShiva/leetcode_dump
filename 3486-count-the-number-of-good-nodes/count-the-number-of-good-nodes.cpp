class Solution {
public:
    int n, ans=0;
    vector<vector<int>> adj;
    int dfs(int i, int parent){
        int cnt=1, child=0;
        bool flag=0, good=1;
        for(int j: adj[i]){
            if (j== parent) continue;
            int x=dfs(j, i);
            if (!flag) child=x, flag=1;
            else if (child!=x) good=0;
            cnt+=x;
        }
        ans+=good;
        return cnt;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        n=edges.size()+1;
        adj.resize(n);
        for(auto& e: edges){
            int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        return ans;
    }

};
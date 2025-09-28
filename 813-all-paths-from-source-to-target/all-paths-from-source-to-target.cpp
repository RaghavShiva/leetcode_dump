class Solution {
public:
    void dfs(int s, int d, vector<vector<int>>& g, vector<int> &p, vector<vector<int>> &ans){
        p.push_back(s);
        if(s==d){
            ans.push_back(p);
            return ;
        }
        for(auto it:g[s]){
            dfs(it,d,g,p,ans);
            p.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0,n-1,graph,path,ans);
        return ans;
    }
};
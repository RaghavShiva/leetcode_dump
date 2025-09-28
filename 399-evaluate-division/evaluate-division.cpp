class Solution {
public:
    void dfs(string s, string d, unordered_map<string, unordered_map<string, double>> &g, unordered_set<string> &vis,double t, double &ans){
        vis.insert(s);
        if(d==s){
            ans = t;
            return;
        }
        for(auto it:g[s]){
            if(vis.find(it.first)==vis.end()){
                dfs(it.first,d,g,vis,t*it.second,ans);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g;
        int n = equations.size();
        for(int i=0;i<n;i++){
            string dd = equations[i][0];
            string d = equations[i][1];
            double v = values[i];
            g[dd][d] = v;
            g[d][dd] = 1/v;
        }
        vector<double> ans;
        for(auto q:queries){
            string dd = q[0];
            string d = q[1];
            if(g.find(dd)==g.end() || g.find(d) == g.end()){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> vis;
            double temp = 1.0, anss = -1.0;
            dfs(dd,d,g,vis,temp,anss);
            ans.push_back(anss);
        }
        return ans;
    }
};
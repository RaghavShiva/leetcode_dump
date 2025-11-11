class Solution {
    int mod = 1e9+7;
public:
    void dfs(int n, int b, vector<int>&v, vector<vector<pair<int,int>>> &g){
        v[n]=b;
        for(auto it:g[n]){
            int c = (b*1ll*it.second)%mod;
            dfs(it.first,c,v,g); 
        }
    }
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        n++;
        vector<int>v(n);
        v[0]=1;
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<n-1;i++){
            g[conversions[i][0]].push_back({conversions[i][1],conversions[i][2]});
        }
        dfs(0,1,v,g);
        return v;
    }
};
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
    /*
    int power(int b, int p){
        int ans=1;
        while(p){
            if(p%2){
                ans = (ans*1ll*b)%mod;
            }
            b = (b*1ll*b)%mod;
            p/=2;
        }
        return ans;
    }
    int clc(int c){
        return power(c,mod-2);
    }
    vector<int> solve(vector<vector<int>> q, vector<int> v, int n){
        vector<int> ans;
        for(auto it:q){
            int c = v[it[0]];
            int d = v[it[1]];
            c = (d*1ll*clc(c)))%mod;
            ans.push_back(c);
        }
        return ans;
    }

    */
};
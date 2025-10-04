class DSU{
    vector<int> par,s;
public:
    DSU(int n){
        par.resize(n+1);
        s.resize(n+1);
        for(int i=0;i<n;i++){
            par[i]=i;
            s[i]=1;
        }
    }
    int find(int n){
        if(par[n]==n){
            return n;
        }
        return par[n] = find(par[n]);
    }
    void unions(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv){
            return;
        }
        if(s[pu]<s[pv]){
            s[pv]+=s[pu];
            par[pu] = par[pv];
        }
        else{
            s[pu]+=s[pv];
            par[pv] = par[pu];
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU ds(n);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                ds.unions(i,i-1);
            }
        }
        vector<bool> ans;
        for(auto q:queries){
            int u = q[0];
            int v = q[1];
            ans.push_back(ds.find(u)==ds.find(v));
        }
        return ans;
    }
};
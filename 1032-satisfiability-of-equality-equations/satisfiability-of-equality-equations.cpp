class Solution {
public:
    class Disjoint{
        vector<int> par,s;
    public:
        Disjoint(){
            par.resize(27);
            s.resize(27);
            for(int i=0;i<26;i++){
                par[i]=i;
                s[i]=1;
            }
        }
        int findP(int u){
            if(u==par[u]) return u;
            return par[u] = findP(par[u]);
        }
        void unionsize(int u, int v){
            int pu = findP(u);
            int pv = findP(v);
            if(pu==pv) return;
            if(s[pu]<s[pv]){
                par[pu]=pv;
                s[pv]+=s[pu];
            }
            else{
                par[pv]=pu;
                s[pu]+=s[pv];
            }
        }
    };
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        Disjoint ds;
        for(int i=0;i<n;i++){
            int u = equations[i][0]-'a';
            int v = equations[i][3]-'a';
            if(equations[i][1]=='='){
                ds.unionsize(u,v);
            }
        }
        for(int i=0;i<n;i++){
            int u = equations[i][0]-'a';
            int v = equations[i][3]-'a';
            if(equations[i][1]=='!'){
                if(ds.findP(u)==ds.findP(v)){
                    return false;
                }
            }
        }
        return true;
    }
};
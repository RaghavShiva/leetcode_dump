class Solution {
public:
    int find(int x, vector<int>& par) {
        if (par[x] < 0)
            return x;
        return par[x] = find(par[x], par);
    }

    void join(int a, int b, vector<int>& par) {
        int pa = find(a, par);
        int pb = find(b, par);
        if (pa == pb)
            return;
        if (par[pa] < par[pb]) {
            par[pa] += par[pb];
            par[pb] = pa;
        } else {
            par[pb] += par[pa];
            par[pa] = pb;
        }
    }
    bool solve(int md, vector<vector<int>> &g, int n, int m, int k, vector<int> &par){
        for(int i=0;i<m;i++){
            int w = g[i][0];
            int u = g[i][1];
            int v = g[i][2];
            if(w>=md){
                if(find(u,par)!=find(v,par)){
                    join(u,v,par);
                }
            }
            else if(w*2>=md && k>0){
                if(find(u,par)!=find(v,par)){
                    join(u,v,par);
                    k--;
                }
            }
        }
            if(par[find(0,par)]==-n){
                return true;
            }
        
        return false;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int m = edges.size();
        vector<int> par(n + 1, -1);
        vector<vector<int>> g;
        int h = 1e6;
        for(int i=0;i<m;i++){
            if(edges[i][3]==1){
                if(find(edges[i][0],par)!=find(edges[i][1],par)){
                    join(edges[i][0],edges[i][1],par);
                    h = min(edges[i][2],h);
                }
                else{
                    return -1;
                }
            }
            else{
                g.push_back({edges[i][2],edges[i][0],edges[i][1]});
            }
        }
        m = g.size();
        sort(g.begin(),g.end(),[](vector<int>&a,vector<int>&b){
            return a[0]>b[0];
        });
        if(par[find(0,par)]==-n){
                return h;
        }
        int t=h;
        int ans=1e6;
        h = 2*g[0][0];
        int l = g[m-1][0];
        
        while(l<=h){
            vector<int> vpar=par;
            int md = (l+h)/2;
            if(solve(md,g,n,m,k,vpar)){
                ans = md;
                l = md+1;
            }
            else{
                h = md-1;
            }
        }
        if(ans==1e6){
            return -1;
        }
        return ans<t?ans:t;
    }
};
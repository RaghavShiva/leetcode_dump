class Solution {
public:
    class Disjoint {
        vector<int> par, s;

    public:
        Disjoint(int n) {
            par.resize(n + 1);
            s.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                par[i] = i;
                s[i] = 1;
            }
        }
        int findP(int n) {
            if (par[n] == n)
                return n;
            return par[n] = findP(par[n]);
        }
        void unionsize(int u, int v) {
            int pu = findP(u);
            int pv = findP(v);
            if (pu == pv)
                return;
            if (s[pu] < s[pv]) {
                par[pu] = pv;
                s[pv] += s[pu];
            } else {
                par[pv] = pu;
                s[pu] += s[pv];
            }
        }
    };
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, int> m;
        int ans = 0;
        int mr=0,mc=0;
        for(int i=0;i<n;i++){
            mr = max(mr, stones[i][0]);
            mc = max(mc,stones[i][1]);
        }
        Disjoint ds(mr+mc+1);
        for(int i=0;i<n;i++){
            int r = stones[i][0];
            int c = stones[i][1]+mr+1;
            ds.unionsize(r,c);
            m[r]++;
            m[c]++;
        }
        for(auto it:m){
            if(ds.findP(it.first)==it.first){
                ans++;
            }
        }
        ans = n - ans;
        return ans;
    }
};
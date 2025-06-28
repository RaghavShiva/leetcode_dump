class Solution {
public:
    int solve(set<int>s){
        if(s.size()==1){
            return 0;
        }
        vector<int> t;
        for(auto it:s){
            t.push_back(it);
        }
        int n = t.size();
        long mn = 1e10;
        for(int i=0;i<n-1;i++){
            // cout<<t[i]<<" ";
            mn = min(mn,abs(t[i]-t[i+1])*1l);
        }
        // cout<<t[n-1]<<endl;
        n = mn;
        return n;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m-k+1,vector<int>(n-k+1,0));
        for(int i=0;i<m-k+1;i++){
            for(int j=0;j<n-k+1;j++){
                set<int> s;
                for(int a=0;a<k;a++){
                    for(int b=0;b<k;b++){
                        s.insert(grid[a+i][b+j]);
                    }
                }
                int c = solve(s);
                ans[i][j] = c;
            }
        }
        return ans;
    }
};
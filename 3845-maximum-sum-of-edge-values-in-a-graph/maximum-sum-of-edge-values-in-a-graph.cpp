class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        ans += (1LL)*n*(n-1);
        ans += (1LL)*n*(n-2);
        for(int i=n-3;i>=1;i--){
            ans += (1LL)*i*(i+2);
        }
        if(edges.size()==n-1){
            return ans;
        }
        return ans+2;
    }
};
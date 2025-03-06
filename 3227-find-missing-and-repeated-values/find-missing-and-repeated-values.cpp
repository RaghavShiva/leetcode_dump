class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum=0;
        long long sq = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
                sq+=(grid[i][j]*1ll*grid[i][j]);
            }
        }
        n = n*n;
        sum = sum - n*(n+1)/2;
        sq = sq -  n*1ll*(n+1)*(2*n+1)/6;
        // cout<<sum<<' '<<sq;
        vector<int> ans(2,0);
        sq = sq/sum;
        ans[0] = (sum+sq)/2;
        ans[1] = (sq-sum)/2;
        return ans;
    }
};
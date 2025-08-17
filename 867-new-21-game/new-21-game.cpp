class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(n==0)
        return 1.0;
        vector<double> dp(n+1,0.0);
        dp[0]=1;
        double sum = k==0 ? 0 : 1;
        double ans=0.0;
        for(int i=1;i<=n;i++){
            dp[i]=sum/maxPts;
            if(i<k){
                sum+=dp[i];
            }
            if(i-maxPts>=0 && i-maxPts < k){
                sum-=dp[i-maxPts];
            }
        }
        ans = accumulate(dp.begin()+k,dp.end(),0.0);
        return ans;
    }
};
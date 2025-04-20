class Solution {
public:
    int helper(vector<int>&p, vector<vector<vector<int>>> &dp, int i, int m,int c){
        if(i>=p.size()){
            return 0;
        }
        if(dp[i][m][c]!=-1){
            return dp[i][m][c];
        }
        int sum=0,t=0;
        if(c%2)
        t=1e7;
        for(int j=1;j<=2*m;j++){
            if(i+j-1<p.size()){
                sum+=p[i+j-1];
                if(c%2)
               t = min(t, helper(p,dp,i+j,max(j,m),0)); 
               else
               t = max(t, sum+helper(p,dp,i+j,max(j,m),1));
            //    cout<<sum<<' '<<c<<endl;
            }
        }
        dp[i][m][c]=t;
        return dp[i][m][c];
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n+1,vector<int>(2,-1)));
        int ans = helper(piles,dp,0,1,0);
        // for(int i=0;i<n;i++){
        //     for(int j=1;j<=2*m;j++){
            
        //     }
        // }
        return ans;
    }
};
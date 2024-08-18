class Solution {
public:
    long long maxEnergyBoost(vector<int>& v1, vector<int>& v2) {
        int n=v1.size();
        vector<long long>dp1(n,0ll),dp2(n,0ll);
        dp1[0]=v1[0];
        dp2[0]=v2[0];
        for(int i=1;i<n;i++){
            if(i>1){
                dp1[i]=max(dp1[i-1],dp2[i-2])+v1[i];
                dp2[i]=max(dp2[i-1],dp1[i-2])+v2[i];
            }
            else{
                dp1[i]=dp1[i-1]+v1[i];
                dp2[i]=dp2[i-1]+v2[i];
            }
        }
      return max(dp1[n-1],dp2[n-1]);
       
    }
};
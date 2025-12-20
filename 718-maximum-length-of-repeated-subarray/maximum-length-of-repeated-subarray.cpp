class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>dp(m+1,0);
        int ans=0;
        for(int i=0;i<m;i++){
            if(nums1[n-1]==nums2[i]){
                dp[i]=1;
                ans=1;
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    dp[j] = 1+dp[j+1];
                }
                else{
                    dp[j]=0;
                }
                ans = max(ans,dp[j]);
            }
        }
        return ans;
    }
};
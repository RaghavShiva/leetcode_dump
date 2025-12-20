class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n,vector<int>(m+1,0));
        int ans=0;
        for(int i=0;i<m;i++){
            if(nums1[n-1]==nums2[i]){
                dp[n-1][i]=1;
                ans=1;
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
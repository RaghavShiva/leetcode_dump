class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans = -1e10;
        int n = nums.size();
        if(m==1){
            for(int i=0;i<n;i++){
                ans = max(ans, 1ll*nums[i]*nums[i]);
            }
            return ans;
        }
        vector<int> mx(n),mn(n);
        mx[n-1] = nums[n-1];
        mn[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            mx[i] = max(mx[i+1],nums[i]);
            mn[i] = min(mn[i+1],nums[i]);
        }
        for(int i=0;i<n-m+1;i++){
            if(nums[i]>=0){
                ans = max(ans, 1ll*mx[i+m-1]*nums[i]);
            }
            else{
                ans = max(ans, 1ll*mn[i+m-1]*nums[i]);
            }
        }
        return ans;
    }
};
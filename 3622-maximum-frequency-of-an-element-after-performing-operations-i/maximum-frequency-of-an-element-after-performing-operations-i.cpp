class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int x = nums[n-1];
        int ans = 1;
        for(int i = 1; i <= x;i++){
            int l = i - k;
            int h = i + k;
            l = lower_bound(nums.begin(),nums.end(), l) - nums.begin();
            h = upper_bound(nums.begin(),nums.end(), h)- nums.begin();
            int t = upper_bound(nums.begin(),nums.end(), i)- nums.begin();
            int tt = lower_bound(nums.begin(),nums.end(), i)- nums.begin();
            t = t - tt;
            l = h - l - t;
            l = min(l,numOperations);
            t = t + l;
            ans = max(ans, t);
        }
         
        return ans;
    }
};
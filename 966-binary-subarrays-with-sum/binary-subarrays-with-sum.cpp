class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i < n; i++){
            nums[i] += nums[i - 1];
        }
        for(int i = 0; i < n; i++){
            int t;
            if(i == 0){
                t = 0;
            }
            else{
                t = nums[i-1];
            }
            int low_lim = lower_bound(nums.begin(), nums.end(), t + goal) - nums.begin();
            int upp_lim = upper_bound(nums.begin(), nums.end(), t + goal) - nums.begin();
            ans += upp_lim - max(low_lim,i);
        }
        return ans;
    }
};
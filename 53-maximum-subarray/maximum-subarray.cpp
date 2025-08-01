class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = -1e4;
        int sub_sum=0;
        
        for(int i=0;i<n;i++){
            sub_sum = max(nums[i], nums[i]+sub_sum); // sub-array sum
            ans = max(ans, sub_sum);
        }
        return ans;
    }
};
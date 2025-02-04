class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int t=nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i]>nums[i-1]){
                t+=nums[i];
            }
            else{
                t = nums[i];
            }
            ans = max(t,ans);
        }
        return ans;
    }
};
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(nums[0]);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, abs(nums[i]-nums[i+1]));
        }
        return ans;
    }
};
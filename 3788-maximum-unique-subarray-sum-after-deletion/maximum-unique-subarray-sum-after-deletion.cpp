class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = -100;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int t = -1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0 && t!=nums[i]){
                if(ans<0)
                ans=0;
                ans += nums[i];
                t = nums[i];
            }
            else if(nums[i]<0){
                ans = max(ans,nums[i]);
            }
        }
        return ans;
    }
};
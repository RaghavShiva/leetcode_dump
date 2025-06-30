class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int c = upper_bound(nums.begin(),nums.end(),nums[i]+1)-nums.begin();
            if(nums[c-1]-nums[i]==1){
                ans = max(ans, c-i);
            }
        }
        return ans;
    }
};
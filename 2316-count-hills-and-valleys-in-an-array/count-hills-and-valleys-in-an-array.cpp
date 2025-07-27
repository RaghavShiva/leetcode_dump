class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i < n-1; i++){
            int h = 0;
            if(nums[i-1]!=nums[i]){
                if(nums[i]>nums[i-1]){
                    h = 1;
                }
                for(int j = i+1; j < n; j++){
                    if(nums[i]==nums[j]) continue;
                    if(nums[i]>nums[j] && h){
                        ans++;
                    }
                    else if(nums[i]<nums[j] && !h){
                        ans++ ;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
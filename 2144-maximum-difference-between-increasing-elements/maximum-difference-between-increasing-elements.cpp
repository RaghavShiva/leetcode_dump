class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans,nums[j]-nums[i]);
            }
        }
        if(ans==0)
        ans=-1;
        return ans;
    }
};
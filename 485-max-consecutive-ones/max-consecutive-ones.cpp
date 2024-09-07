class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0,cnt=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)
            cnt=0;
            else
            cnt++;
            mx=max(mx,cnt);
        }
        return mx;
    }
};
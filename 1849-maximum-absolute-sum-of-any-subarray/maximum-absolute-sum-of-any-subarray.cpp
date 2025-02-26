class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0;
        int t = 0;
        int tt=0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(t+nums[i]<0){
                t=0;
            }
            else
                t+=nums[i];
                nums[i]=-1*nums[i];
            if(tt+nums[i]<0){
                tt=0;
            }
            else
                tt+=nums[i];  
        
         ans = max(ans,tt);
         ans = max(ans,t);
        }
         return ans;
    }
};
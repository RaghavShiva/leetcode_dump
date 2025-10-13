class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l=0,ans=0,sum=0,cnt=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(l<r && (nums[l]==0 || sum>goal)){
                if(nums[l]==0){
                    cnt++;
                }
                else{
                    cnt=0;
                }
                sum-=nums[l];
                l++;
            }
            if(sum==goal){
                ans += 1+cnt;
            }
        }
        return ans;
    }
};
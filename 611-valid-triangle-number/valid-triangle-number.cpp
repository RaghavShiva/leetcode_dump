class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return 0;
        }
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k = lower_bound(nums.begin(),nums.end(),nums[i]+nums[j])-nums.begin();
                if(k-j>0)
                ans += k-1-j;
            }
        }
        return ans;
    }
};
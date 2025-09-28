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
            int k = 0;
            for(int j=i+1;j<n;j++){
                k = max(k,j+1);
                while(k<n && nums[i]+nums[j]>nums[k]){
                    k++;
                }
                ans += k-1-j;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end(),greater());
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=i+1;j<n;j++){
                k=max(k,j+1);
                while(k<n && nums[i]-nums[j]<nums[k]){
                    ans = max(ans,nums[i]+nums[j]+nums[k]);
                    k++;
                }
            }
        }
        return ans;
    }
};
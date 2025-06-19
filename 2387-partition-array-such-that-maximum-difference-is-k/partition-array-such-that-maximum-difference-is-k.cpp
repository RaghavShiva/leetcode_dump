class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int t = nums[0];
        int ans = 0;
        for(int i=0;i<n;i++){
            if(t+k < nums[i]){
                ans++;
                t = nums[i];
            }
            cout<<ans<<" ";
        }
        ans++;
        return ans;
    }
};
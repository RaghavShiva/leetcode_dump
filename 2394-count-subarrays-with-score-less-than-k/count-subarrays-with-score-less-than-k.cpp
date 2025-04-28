class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0,r=0;
        int n = nums.size();
        long long ans = 0;
        long long temp = 0;
        while(r<n){
            temp+=nums[r];
            while(l<=r && (r-l+1)*temp >= k){
                temp -= nums[l];
                l++;
            }
            ans+=r-l+1;
           r++;
        }
        
        return ans;
    }
};
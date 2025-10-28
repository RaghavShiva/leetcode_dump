class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0;
        long long p = 1;
        int ans = 0;
        while(l<n){
            if(r<n && p*1ll*nums[r]<k){
                p=p*nums[r];
                r++;
            }
            else{
                if(p<k)
                ans += r-l;
                p = p/nums[l];
                l++;
                if(l>r){
                    r=l;
                    p=1;
                }
            }
        }
        if(p<k){
            ans+=r-l;
        }
        return ans;
    }
};
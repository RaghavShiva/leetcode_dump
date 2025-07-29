class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        vector<int> v(31,n);
        for(int i = n-1;i>=0;i--){
            int c  = i;
            for(int j = 0; j < 31; j++){
                int b = nums[i] & (1ll<<j);
                if(!b && v[j]!=n){
                    c = max(c,v[j]);
                }
                if(b){
                    v[j] = i;
                }
            }
            ans[i] = c-i+1;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>p(n), s(n);
        p[0] = 1;
        s[n-1] = 1;
        for( int i = 0; i < n-1; i++){
            p[i+1] = p[i] * nums[i];
            s[n-2-i] = s[n-1-i] * nums[n-1-i]; 
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = p[i] * s[i];
        }
        return ans;
    }
};
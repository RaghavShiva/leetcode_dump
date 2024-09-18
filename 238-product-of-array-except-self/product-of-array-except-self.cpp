class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>p(n);
        p[0] = 1;
        int t = 1;
        for( int i = 0; i < n-1; i++){
            p[i+1] = p[i] * nums[i];
        }
        
        for(int i = n - 1; i >= 0; i--){
            p[i] = p[i] * t;
            t = t * nums[i];
        }
        return p;
    }
};
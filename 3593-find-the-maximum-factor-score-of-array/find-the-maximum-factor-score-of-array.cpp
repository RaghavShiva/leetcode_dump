class Solution {
public:
    long long solve(int x, vector<int>&nums){
        int n = nums.size();
        long long gc = 0ll, lc = 1ll;
        long long ans = 0;
       
        for(int i =0;i<n;i++){
            if(i==x){
                continue;
            }
            gc = __gcd(gc, 1ll*nums[i]);
            lc = lcm(lc, 1ll*nums[i]);
        }
        ans = gc * lc;
        return ans;
    }
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = solve(-1, nums);
        for(int i = 0; i < n; i++){
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
};
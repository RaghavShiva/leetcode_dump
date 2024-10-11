class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0;
        if(n == 1){
            return 0;
        }
        while(r < n){
            int mx = 0;
            for(int i = l; i <= r; i++){
                mx = max(mx, i + nums[i]);
            }
            ans++;
            l = r + 1;
            r = mx;
            if(r >= n - 1){
                return ans;
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pg(n,0),ng(n,0);
        int t = nums[0];
        for(int i=1;i<n;i++){
            pg[i] = t;
            t = max(t,nums[i]);
        }
        t = nums[n-1];
        for(int i=n-2;i>=0;i--){
            ng[i] = t;
            t = max(t,nums[i]);
        }
        long long ans = 0ll;
        for(int i=1;i<n-1;i++){
            ans = max(ans, 1ll*(pg[i]-nums[i])*ng[i]);
        }
        return ans;
    }
};
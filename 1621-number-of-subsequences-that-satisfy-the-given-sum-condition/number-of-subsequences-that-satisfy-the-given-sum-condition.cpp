class Solution {
public:
    int mod = 1e9+7;
    int power(int x, int n){
        int res = 1;
        while(n){
            if (n & 1)
                res = (res*1ll*x)%mod;
            n = n / 2;
            x = (x*1ll*x)%mod;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
       int n = nums.size();
       sort(nums.begin(),nums.end());
       int ans = 0;
       for(int i=0;i<n;i++){
        int c = upper_bound(nums.begin(),nums.end(),target-nums[i])-nums.begin();
        if(c<=i){
            continue;
        }
        c = c-i;
        ans = (ans+power(2,c-1))%mod;
        cout<<ans<<' ';
       } 
       return ans;
    }
};
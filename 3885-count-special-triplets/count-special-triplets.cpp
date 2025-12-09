class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>mp,m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        int mod = 1e9+7;
        int ans = 0;

        for(int i=0;i<n;i++){
            mp[nums[i]]--;
            ans = (ans + 1ll*m[nums[i]*2]*mp[nums[i]*2])%mod;
            m[nums[i]]++;
        }
        return ans;
    }
};
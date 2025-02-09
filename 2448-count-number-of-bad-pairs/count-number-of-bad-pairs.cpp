class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int>m;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i]-=i;
            m[nums[i]]++;
        }
        long long ans = n*1ll*(n-1)/2;
        for(auto it:m){
            long long t = it.second;
            t = t*(t-1)/2;
            ans-=t;
        }
        return ans;
    }
};
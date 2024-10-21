class Solution {
public:
    void helper(int n, vector<int> &v){
        v[1] = 1;
        for(int i = 2; i <= n; i++){
            if(!v[i]){
                v[i] = i;
                for(int j = i + i; j <= n; j+=i){
                    if(!v[j])
                    v[j] = i;
                }
            }
        }
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int mx = *max_element(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] >= nums[i - 1]){
                ans++;
            }
        }
        if(ans == n){
            return 0;
        }
        ans = 0;
        vector<int> primefac(mx + 1, 0);
        helper(mx, primefac);
        
        for(int i = n-1; i >= 0; i--){
            if(i != n-1 && nums[i] > nums[i + 1]){
                nums[i] = primefac[nums[i]];
                ans++;
            }
          
        }
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] < nums[i - 1]){
             return -1;
            }
        }
        return ans;
    }
};
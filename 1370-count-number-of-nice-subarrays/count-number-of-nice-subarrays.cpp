class Solution {
public:
    int count_k(vector<int>&nums, int k){
        int cnt = 0;
        int n = nums.size();
        int o = 0, j = 0;
        for(int i = 0; i < n; i++){
            while(o < k && j < n){
                if(nums[j] == 1){
                    o++;
                }
                j++;
            }
            if(o >= k){
                cnt += n - max(i,j-1);
            }
            if(nums[i] == 1){
                o--;
            }
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] %= 2;
        }
        return count_k(nums, k) - count_k(nums, k + 1) ;
    }
};
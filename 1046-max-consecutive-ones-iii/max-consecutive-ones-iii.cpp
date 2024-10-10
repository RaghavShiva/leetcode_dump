class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int n = nums.size();
        int maxlen = 0, len = 0;
        int lt = 0, rt = 0;
        while(rt < n){
            if(nums[rt] == 0){
                zeros++;
            }
            if(zeros <= k){
                len++;
            }
            else{
                if(nums[lt] == 0){
                    zeros--;
                }
                lt++;
            }

            rt++;
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};
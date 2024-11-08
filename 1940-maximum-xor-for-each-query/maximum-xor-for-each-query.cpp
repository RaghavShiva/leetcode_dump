class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]^nums[i];
        }
        reverse(pre.begin(),pre.end());
        for(int i=0;i<n;i++){
            pre[i]=((1<<maximumBit)-1)^pre[i];
        }
        return pre;
    }
};
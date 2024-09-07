class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur=0;
        int n = nums.size();
        if(n==1)
        return n;
        for(int i=1;i<n;i++){
            if(nums[cur]==nums[i]){
                continue;
            }else if(nums[cur]<nums[i]){
                nums[cur+1]=nums[i];
                cur++;
            }
        }
        return cur+1;
    }
};
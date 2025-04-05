class Solution {
public:
    int sum(vector<int>&nums,int i,int ans){
        if(i==nums.size()){
            return ans;
        }
        int t = sum(nums,i+1,ans^nums[i]);
        int nt = sum(nums,i+1,ans);
        return t+nt;
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        return sum(nums,0,ans);
    }
};
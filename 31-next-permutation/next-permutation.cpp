class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int f = -1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                f=i-1;
                break;
            }
        }
        if(f==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1;i>f;i--){
                if(nums[i]>nums[f]){
                    swap(nums[i],nums[f]);
                    reverse(nums.begin()+f+1,nums.end());
                    break;
                }
            }
        }
    }
};
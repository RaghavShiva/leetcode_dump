class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int l=0,r=0;
        while(r<n){
            if(nums[l]==0 && nums[r]>0){
                swap(nums[l],nums[r]);
                l++;
                r++;
                continue;
            }
            if(nums[l]==0){
                r++;
            }
            else{
                l++;
                r++;
            }
        }
        return nums;
    }
};
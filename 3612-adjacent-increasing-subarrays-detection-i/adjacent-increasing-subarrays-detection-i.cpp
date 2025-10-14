class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<=n-2*k;i++){
            int p=-1e9;
            bool f = true;
            for(int j=0;j<2*k;j++){
                if(j==k){
                    p=-1e9;
                }
                if(p<nums[i+j]){
                    p=nums[i+j];
                }
                else{
                    f=false;
                    break;
                }
            }
            if(f){
                return true;
            }
        }
        return false;
    }
};
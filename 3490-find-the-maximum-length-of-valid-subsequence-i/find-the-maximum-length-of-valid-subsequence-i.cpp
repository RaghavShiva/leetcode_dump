class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%2;
        }
        int c0=0,c1=0,t=nums[0],ct=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
            c0++;
            if(nums[i])
            c1++;
            if(t!=nums[i]){
                t=nums[i];
                ct++;
            }
        }
        return max(ct,max(c0,c1));
    }
};
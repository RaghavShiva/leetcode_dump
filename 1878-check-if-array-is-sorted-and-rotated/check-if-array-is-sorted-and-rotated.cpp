class Solution {
public:
    bool check(vector<int>& nums) {
        int t=0,c=100;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            t=nums[i]-nums[i+1];
            if(t>0){
                if(c==100)
                c=nums[i];
                else
                return false;
            }
            if(nums[i]>c)
            return false;
        }
        if(nums[n-1]>c || (c!=100 && nums[0]<nums[n-1]))
        return false;
      
        return true;
    }
};
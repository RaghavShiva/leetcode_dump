class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int c = 0;
        int n = nums.size();
        int t = nums[0];
        for(int i=0;i<n-1;i++){
            if(t==-1){
                c++;
                t = nums[i+1]*-1;
            }
            else
            t=nums[i+1];
        }
        if(c<=k && t==1){
            return true;
        }
        c=0;
        t = nums[0];
        for(int i=0;i<n-1;i++){
            if(t==1){
                c++;
                t = nums[i+1]*-1;
            }
            else
            t=nums[i+1];
        }
        if(c<=k && t==-1){
            return true;
        }
        return false;
    }
};
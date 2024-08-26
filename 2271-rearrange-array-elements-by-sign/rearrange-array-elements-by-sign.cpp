class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p=0,n=0;
        int s=nums.size();
        vector<int>ans(s);
        for(int i=0;i<s;i++){
            if(nums[i]>0){
                ans[2*p]=nums[i];
                p++;
            }
            else{
                ans[2*n+1]=nums[i];
                n++;
            }
        }
    return ans;
    }
};
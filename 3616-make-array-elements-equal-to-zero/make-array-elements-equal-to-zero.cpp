class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int s=0,p=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(s-p==1 || s-p==0){
                    ans++;
                }
                if(p-s==1 || p-s==0){
                    ans++;
                }
            }
            s-=nums[i];
            p+=nums[i];
        }
        return ans;
    }
};
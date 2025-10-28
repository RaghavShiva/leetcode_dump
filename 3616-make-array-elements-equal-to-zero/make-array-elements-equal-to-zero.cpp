class Solution {
public:
    bool solve(int i, int d, vector<int> nums){
        int n = nums.size();
        while(i>=0 && i<n){
            if(nums[i]==0){
                i+=d;
            }
            else{
                nums[i]--;
                d*=(-1);
                i+=d;
            }
        }
        for(int j=0;j<n;j++){
            if(nums[j]!=0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(solve(i,-1,nums)){
                    ans++;
                }
                if(solve(i,1,nums)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
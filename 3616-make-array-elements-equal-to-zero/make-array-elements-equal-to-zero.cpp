class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> v(n+1,0);
        for(int i=0;i<n;i++){
            v[i+1] = v[i]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if((v[n]-v[i])-v[i]==1 || (v[n]-v[i])-v[i]==0){
                    ans++;
                }
                if(v[i]-(v[n]-v[i])==1 || v[i]-(v[n]-v[i])==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> f(mx,0);
        for(int i=0;i<n;i++){
            f[nums[i]-1]++;
        }
        int ans=0;
        int cur=0;
        for(int i=0;i<mx;i++){
            if(f[i]>cur){
                cur=f[i];
                ans=f[i];
            }
            else if(f[i]==cur){
                ans+=f[i];
            }
        }
        return ans;
    }
};
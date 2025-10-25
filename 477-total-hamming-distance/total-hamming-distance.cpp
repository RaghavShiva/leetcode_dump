class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int t=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                t=nums[i]^nums[j];
                ans+=__builtin_popcount(t);
            }
        }
        return ans;
    }
};
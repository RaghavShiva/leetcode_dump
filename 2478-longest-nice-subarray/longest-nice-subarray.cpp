class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int t = nums[i];
            int cnt = 1;
            for(int j=i+1;j<n;j++){
                if(t&nums[j]){
                    break;
                }
                t=t|nums[j];
                cnt++;
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, sum=0,l=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            while(m[nums[i]]>0){
                sum -= nums[l];
                m[nums[l]]=-1;
                l++;
            }
            m[nums[i]] = i+1;
            sum += nums[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};
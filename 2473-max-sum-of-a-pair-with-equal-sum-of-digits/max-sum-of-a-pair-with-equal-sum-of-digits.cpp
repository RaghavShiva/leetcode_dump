class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int,int>>sum;
        for(int i =0 ;i < nums.size();i++){
            int s = 0;
            int n = nums[i];
            do{
                s+=n%10;
                n/=10;
            }
            while(n);
            sum.push_back({s,nums[i]});
        }
        sort(sum.begin(),sum.end());

        int ans = -1;
        for(int i = 0;i < nums.size()-1;i++){
            if(sum[i].first==sum[i+1].first){
                ans = max(ans,sum[i].second+sum[i+1].second);
            }
        }
        return ans;
    }
};
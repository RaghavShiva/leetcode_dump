class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pq.push({nums[i],i});
        }
        long long ans = 0ll;
        while(!pq.empty()){
            int t = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            if(nums[i]!=-1){
                if(i>0){
                    nums[i-1]=-1;
                }
                if(i<n-1){
                    nums[i+1]=-1;
                }
                ans += nums[i];
                nums[i]=-1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long ans = LLONG_MAX;
        int n = nums.size();
        n=n/3;
        priority_queue<int> pq;
        vector<long long> v;
        long long sum = 0;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            sum+=nums[i];
        }
        v.push_back(sum);
        for(int i=n;i<2*n;i++){
            pq.push(nums[i]);
            sum += nums[i];
            int t = pq.top();
            pq.pop();
            sum-=t;
            v.push_back(sum);
        }
        priority_queue<int,vector<int>, greater<int>> pp;
        sum = 0;
        for(int i = 3*n-1;i>=2*n;i--){
            pp.push(nums[i]);
            sum+=nums[i];
        }
        int j=n;
        ans = min(ans, v[j]-sum);
        for(int i=2*n-1;i>=n;i--){
            j--;
            pp.push(nums[i]);
            sum += nums[i];
            int t = pp.top();
            pp.pop();
            sum-=t;
            ans = min(ans, v[j]-sum);
        }
        return ans;
    }
};
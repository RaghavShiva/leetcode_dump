class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> pre(n+1, 0);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            pre[i+1] += pre[i] + nums[i];
        }
        map<int, int> m;
        int l = 0, r = 0;
        while(r < n){
            m[nums[r]]++;
            r++;
            if((r-l) == k){
                if(m.size() < x){
                    ans.push_back(pre[r] - pre[l]);
                }
                else{
                priority_queue<pair<int,int>> pq;
                for(auto x : m){
                    pq.push({x.second, x.first});
                }
                int temp = 0;
                for(int i = 0; i < x; i++){
                    temp += pq.top().first*pq.top().second;
                    pq.pop();
                }
                
                
                ans.push_back(temp);
                }
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    m.erase(nums[l]);
                }
                l++;
            }
        }
        return ans;
    }
};
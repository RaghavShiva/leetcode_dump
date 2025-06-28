class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<pair<int,int>>v(k);

        vector<int> ans(k);
        for(int i=0;i<k;i++){
            auto it = pq.top();
            v[i] = {it.second,it.first};
            pq.pop();
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++){
            ans[i] = v[i].second;
        }
        return ans;
    }
};
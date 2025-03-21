class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums1[i],i});
        }
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>, greater<int>> pq;
        // pq.push(0);
        while(k--){
            pq.push(0ll);
        }
        long long sum=0ll,c=0ll;
        int t = v[0].first;
        vector<long long> ans(n,0);
        for(int i=0;i<n;i++){
            int x = pq.top();
            pq.pop();
            if(t<v[i].first){
                t = v[i].first;
                ans[v[i].second]=sum;
                c=sum;
            }
            else{
                ans[v[i].second]=c;
            }
                if(nums2[v[i].second]>x){
                    sum-=x;
                    sum+=nums2[v[i].second];
                    pq.push(nums2[v[i].second]);
                }
                else{
                    pq.push(x);
                }
                
        }
        return ans;
    }
};
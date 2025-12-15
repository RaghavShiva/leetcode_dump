class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({technique1[i]-technique2[i],i});
        }
        long long ans=0;
        while(k--){
            ans+=technique1[pq.top().second];
            pq.pop();
        }
        while(!pq.empty()){
            int a = technique1[pq.top().second];
            int b = technique2[pq.top().second];
            ans+=max(a,b);
            pq.pop();
        }
        return ans;
    }
};

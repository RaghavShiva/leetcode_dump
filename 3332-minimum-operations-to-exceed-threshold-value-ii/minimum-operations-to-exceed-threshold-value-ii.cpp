class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
     priority_queue<long long,vector<long long>,greater<long long>> pq;
     for(int n:nums){
        pq.push(n);
     }   
     int ans = 0;
     while(pq.size()>1){
        long long x = pq.top();
        if(x>=k){
            break;
        }
        pq.pop();
        ans++;
        long long y = pq.top();
        pq.pop();
        x = 2ll*x+y;
        pq.push(x);
       
     }
     return ans;
    }
};
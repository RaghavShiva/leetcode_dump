class Solution {
public:
    int integerReplacement(int n) {
        priority_queue<pair<int,long long>,vector<pair<int,long long>>,greater<pair<int,long long>>> pq;
        pq.push({0,n});
        while(!pq.empty()){
            int o = pq.top().first;
            long long i = pq.top().second;
            pq.pop();
            if(i==1){
                return o;
            }
            if(i%2==0){
                pq.push({o+1,i/2});
            }
            else{   
                pq.push({o+1,i+1});
                pq.push({o+1,i-1});
            }
        }
        return 0;
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        int ans = 0;
        unordered_map<long long,bool> m;
        m[1] = true;
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        pq.push(1);
        while(!pq.empty()){
            long long i = pq.top();
            pq.pop();
            n--;
            if(n==0){
                return i;
            }
            if(m.find(i*2)==m.end()){
                pq.push(i*2);
                m[i*2]=true;
            }
            if(m.find(i*3)==m.end()){
                pq.push(i*3);
                m[i*3]=true;
            }
            if(m.find(i*5)==m.end()){
                pq.push(i*5);
                m[i*5]=true;
            }
        }
        return 1;
    }
};
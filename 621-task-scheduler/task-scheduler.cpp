class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>f(26,0);
        int m=tasks.size();
        for(int i=0;i<m;i++){
            f[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(f[i]!=0){
                pq.push(f[i]);
            }
        }
        int ans=0;
        
        while(!pq.empty()){
            vector<int>t;
            int tt=n;
           while(!pq.empty()&&tt>=0){
                 t.push_back(pq.top());
                 pq.pop();
                 --tt;
           }
           for(auto val:t){
              if(val-1!=0)
              pq.push(val-1);
           }
           if(pq.empty())
           ans+=t.size();
           else
           ans+=n+1;
    }
        return ans;
    }
};
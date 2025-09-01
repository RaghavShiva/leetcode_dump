class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int x) {
         priority_queue<pair<double,int>> pq;
         int n = classes.size();
         for(int i=0;i<n;i++){
            int p = classes[i][0];
            int t = classes[i][1];
            double c = (p+1)*1.0/(t+1)-p*1.0/t;
            pq.push({c,i});
         }
         while(x--){
            int i = pq.top().second;
            pq.pop();
            classes[i][0]++;;
            classes[i][1]++;
            int p = classes[i][0];
            int t = classes[i][1];
            double c = (p+1)*1.0/(t+1)-p*1.0/t;
            pq.push({c,i});
         }
         double ans = 0.0;
         while(!pq.empty()){
            int i = pq.top().second;
            pq.pop();
            int p = classes[i][0];
            int t = classes[i][1];
            ans += p*1.0/t;
         }
         ans = ans/n;
        return ans;
    }
};
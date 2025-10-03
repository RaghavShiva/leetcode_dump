class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        if(k==1 && n!=1){
            return -1.0;
        }
        int ms = 1<<n;
        priority_queue<pair<double,tuple<int,int,int>>, vector<pair<double,tuple<int,int,int>>>, greater<pair<double,tuple<int,int,int>>>> pq;
        map<tuple<int,int,int>,double> tt;
        vector<int> mx(ms,0);
        for(int i=1;i<ms;i++){
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    mx[i] = max(mx[i],time[j]);
                }
            }
        }
        pq.push({0.0,{0,0,0}});
        tt[{0,0,0}] = 0.0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double t = it.first;
            auto itt = it.second;
            int st = get<0>(itt);
            int b = get<1>(itt);
            int f = get<2>(itt);
            if(b==(ms-1)) return t;
            if(tt[{st,b,f}]<t) continue;

            if(!f){
                for(int i = 1;i<ms;i++){
                    int n_b = __builtin_popcount(i);
                    if(n_b > k || i&b) continue;
                    int nb = b|i;
                    double nt = mx[i]*mul[st];
                    int nst = (st+(int)floor(nt))%m;
                    nt+=t;
                    if(tt.find({nst,nb,1})==tt.end() || nt<tt[{nst,nb,1}]){
                        tt[{nst,nb,1}] = nt;
                        pq.push({nt,{nst,nb,1}});
                    }
                }
            }
            else{
                for(int i = 0;i<n;i++){
                    if(!(b&(1<<i))) continue;
                    int nb = b&~(1<<i);
                    double nt = time[i]*mul[st];
                    int nst = (st+(int)floor(nt))%m;
                    nt+=t;
                    if(tt.find({nst,nb,0})==tt.end() || nt<tt[{nst,nb,0}]){
                        tt[{nst,nb,0}] = nt;
                        pq.push({nt,{nst,nb,0}});
                    }
                }
            }
        }
        return -1;
    }
};
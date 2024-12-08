class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<int> suf(n);
        suf[n-1] = events[n-1][2];
        for(int i = 1; i < n; i++){
            suf[n-1-i] = max(suf[n-i],events[n-1-i][2]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int d = events[i][1];
            int v = events[i][2];
            int l = i+1, h = n-1, m;
            int ind = -1;
            while(l <= h){
                m = (l+h)/2;
                if(d < events[m][0]){
                    h = m - 1;
                    ind = m;
                }
                else{
                    l = m + 1;
                }
            }
            cout<<ind<<' ';
            if(ind!=-1){
                v += suf[ind];
            }
            ans = max(v,ans);
        }
        
        return ans;
    }
};
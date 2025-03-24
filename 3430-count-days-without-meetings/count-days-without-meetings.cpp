class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int cnt=0,t=0;
        for(auto x:meetings){
            if(t>=x[1])
            continue;
            if(t>=x[0])
            cnt+=x[1]-t;
            else
            cnt+=x[1]-x[0]+1;
            t=x[1];
            
        }
        return days-cnt;
    }
};
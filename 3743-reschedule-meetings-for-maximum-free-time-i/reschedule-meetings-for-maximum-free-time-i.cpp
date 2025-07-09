class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>v(n+1,0);
        v[0]=startTime[0]-0;
        v[n]=eventTime-endTime[n-1];
        for(int i =1;i<n;i++){
            v[i]=startTime[i]-endTime[i-1];
        }
        int ans=0;
        int t=0;
        for(int i=0;i<=k;i++){
            t+=v[i];
        }
        ans=t;
        for(int i=k+1;i<=n;i++){
            t-=v[i-k-1];
            t+=v[i];
            ans=max(t,ans);
        }
        return ans;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int>v(n+1,0);
        vector<pair<int,int>>cnt(n+1);
        cnt[0]={0,1};
        for(int i=0;i<n;i++){
            v[i+1]+=v[i]+arr[i];
            if(v[i+1]%2){
                cnt[i+1]={cnt[i].first+1,cnt[i].second};
            } 
            else{
                cnt[i+1]={cnt[i].first,cnt[i].second+1};
            }
        }
        int ans=0;
        int mod = 1e9+7;
        for(int i=1;i<=n;i++){
            if(v[i]%2){
                ans = (ans+0ll+cnt[i].second)%mod;
            }
            else{
                ans = (ans+0ll+cnt[i].first)%mod;
            }
        }
        return ans;
    }
};
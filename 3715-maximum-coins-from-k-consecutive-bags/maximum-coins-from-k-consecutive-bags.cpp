#include<bits/stdc++.h>
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<pair<long,long>> v;
        long long x = 0ll;
        long long ans = 0ll;
        for(auto it:coins){
            int l = it[0];
            int r = it[1];
            int c = it[2]; 
            v.push_back({l-1ll,x});
            x += (r-l+1)*1ll*c;
            v.push_back({r,x});
        }
        v.push_back({2e9+1,x});
        for(int i = 0; i < n; i++){
            int t = lower_bound(v.begin(),v.end(),make_pair(v[2*i].first+k,0))-v.begin();
            if(t%2==0){
                ans = max(ans, 1ll*v[t].second-v[2*i].second);
            }
            else{
                long long tm = v[t].second-v[2*i].second;
                t = (t-1)/2;
                tm = tm -( coins[t][1]-(v[2*i].first+k))*(coins[t][2]);
                ans = max(ans, tm);
            }
        }
        for(int i = 0; i < n; i++){
            int t = upper_bound(v.begin(),v.end(),make_pair(v[2*i+1].first-k,0))-v.begin();
            if(t%2==0){
                ans = max(ans, 1ll*v[2*i+1].second-v[t].second);
            }
            else{
                long long tm = v[2*i+1].second-v[t].second;
                t = (t-1)/2;
                tm = tm +( coins[t][1]-(v[2*i+1].first-k))*(coins[t][2]);
                ans = max(ans, tm);
            }
        }
        return ans;
    }
};
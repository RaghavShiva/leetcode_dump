class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
   
        unordered_map<long long, long long> freq;
        for(int i=0;i<power.size();i++)
            freq[power[i]]++;
        vector<long long> v;
        for (auto it : freq) {
            v.push_back(it.first*1ll);
        }
        sort(v.begin(),v.end());
        int n=v.size();
        vector<long long>dp(n+1,0ll);
        if(n==1){
            return static_cast<long long>(v[0]*freq[v[0]]);
        }
        for (int i = 1; i <= n; ++i) {
            long long t =static_cast<long long> (v[i - 1]*1ll*freq[v[i-1]]*1ll);
            
            for (int j = i - 2; j >= 0; --j) {
                if ((v[i - 1] - v[j]) > 2) {
                    t = t+ dp[j + 1];
                    break;
                }
            }
            
            long long nt = dp[i - 1];
            dp[i] = max(t, nt);
        }
        
        return dp[n];
 

    }
};
class Solution {
public:
    long long expmod(int n, int x){
        int mod = 1e9+7;
        long long ans = 1ll;
        while(x>0){
            if(x%2){
                ans = (ans*1ll*n)%mod;
            }
            x=x/2;
            n = (n*1ll*n)%mod;
        }
        return ans;
    }
    
    void sieve(vector<bool>&v,int mx){
        v[0]=false;
        v[1]=v[0];
        for(int i=2;i<=mx;i++){
            if(v[i]){
                for(int j=i*2;j<=mx;j+=i){
                    v[j]=false;
                }
            }
        }
    }
    int maximumScore(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(),nums.end());
        vector<bool> v(mx+1,true);
        sieve(v,mx);
        int n = nums.size();
        unordered_map<int,int>m;
        m[1]=0;
        for(int i=0;i<n;i++){
            if(!m[nums[i]]){
                int cnt=0;
                int t = nums[i];
                for(int j=1;j*j<=t;j++){
                    if(j*j==t){
                        if(v[j]){
                            cnt++;
                            continue;
                        }
                    }
                    if(t%j==0){
                        if(v[j]){
                            cnt++;
                        }
                        if(v[t/j]){
                            cnt++;
                        }
                    }
                }
                m[nums[i]] = cnt;
            }
        }
        vector<int>ps(n);
        for(int i=0;i<n;i++){
            ps[i]=m[nums[i]];
        }
        stack<int>s;
        vector<int>lt(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && ps[s.top()]<ps[i]){
                s.pop();
            } 
            if(s.empty()){
                lt[i]=0;
            }
            else{
                lt[i]=s.top()+1;
            }
            s.push(i);
        }
        vector<int> rt(n);
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && ps[s.top()]<=ps[i]){
                s.pop();
            } 
            if(s.empty()){
                rt[i]=n-1;
            }
            else{
                rt[i]=s.top()-1;
            }
            s.push(i);
        }
        
        vector<pair<int,long long>> ct(n);
        for(int i=0;i<n;i++){
            ct[i]={nums[i],(rt[i]-i+1)*1ll*(i-lt[i]+1)};
            cout<<ct[i].first<<' '<<ct[i].second<<endl;
        }
        long long ans = 1ll, mod = 1e9+7;
        sort(ct.begin(),ct.end(),greater<pair<int,int>>());
        for(int i=0;i<n;i++){
            if(ct[i].second<=k){
                k-=ct[i].second;
                long long t = expmod(ct[i].first,ct[i].second);
                ans = (t*ans)%mod;
            }
            else{
                long long t = expmod(ct[i].first,k);
                ans = (ans*t)%mod;
                k=0;
            }
            if(k==0){
                break;
            }
        }
        return ans;
    }
};
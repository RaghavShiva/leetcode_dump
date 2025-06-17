#define ll long long int
#define fo(i,a,b) for(ll i=a;i<b;++i)
class Solution {
public:
    ll factorial(ll n)
{
  ll M = 1000000007;

  ll f = 1,i;
  fo(i,1,n+1)
    f = (f *1ll* i) % M; // Now f never can
  // exceed 10^9+7
  return f;
}

ll powerLL(ll x, ll n)
{
  ll MOD = 1e9+7;
  ll result = 1ll;
  while (n) {
    if (n & 1)
      result = (result*1ll*x)%MOD;
    n = n / 2;
    x = (x*1ll*x)%MOD;
  }
  return result;
}
ll multiplicative_mod_inverse(ll n){
    ll m=1e9+7;
    ll ans = powerLL(n,m-2);
    return ans;
}

ll ncr(ll n,ll r){
    ll mod=1e9+7;
    ll den=(factorial(n-r)*1ll*factorial(r))%mod;
    ll ans=factorial(n);
    ans=(ans*1ll*multiplicative_mod_inverse(den))%mod;
    return ans;
}
    int countGoodArrays(int n, int m, int k) {
        int mod = 1e9+7;
        int ans = 0;
        ans = ((m * powerLL(m-1,n-k-1))%mod*ncr(n-1,k))%mod;
        return ans;
    }
};
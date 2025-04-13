class Solution {
    int mod = 1e9+7;
public:
    long long fun(long long b, long long p){
        long long ans = 1;
        while(p){
            if(p%2){
                ans = (ans*b)%mod;
            }
            b = (b*b)%mod;
            p=p/2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long a=n/2;
        long long b = n/2;
        if(n%2){
            a++;
        }
        a = (fun(5,a)*fun(4,b))%mod;
        return a;
    }
};
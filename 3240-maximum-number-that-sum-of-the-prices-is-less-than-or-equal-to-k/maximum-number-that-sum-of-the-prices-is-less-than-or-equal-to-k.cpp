class Solution {
public:
    bool helper(long long m, long long k, int x){
        m++;
        int t = ceil(log(m)*1.0/log(2));
        int i=0;
        long long cnt=0;
        while(i<=t){
            i++;
            if(i%x!=0) continue;
            long long c = (1ll<<i);
            cnt += ((m/c)*(c/2));
            cnt += max(0ll,m%c-c/2);
            if(m==8){

            }
            if(cnt>k){
                return false;
            }
        }

        return cnt<=k;
    }
    long long findMaximumNumber(long long k, int x) {
        long long l=0,h=1e15,m=0;
        long long ans=0;
        while(l<=h){
            m = l+(h-l)/2;
            if(helper(m,k,x)){
                ans=m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return ans;
    }
};
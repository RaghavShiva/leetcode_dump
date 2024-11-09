class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        n--;
        for(int i = 0; i < 64; i++){
            if(!(ans&(1ll<<i))){
                ans = ans|((n&1)?(1ll<<i):0);
                n=n>>1;
            }
            if(n==0)
            break;
        }
        return ans;
    }
};
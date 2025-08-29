class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans=0;
        ans += (n+1)/2*1ll*(m/2);
        ans += (m+1)/2*1ll*(n/2);
        return ans;
    }
};
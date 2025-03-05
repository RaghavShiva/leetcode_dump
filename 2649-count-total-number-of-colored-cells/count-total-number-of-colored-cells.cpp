class Solution {
public:
    long long coloredCells(int n) {
        long long ans=0;
        ans = n*1ll*(n-1)/2*4+1;
        return ans;
    }
};
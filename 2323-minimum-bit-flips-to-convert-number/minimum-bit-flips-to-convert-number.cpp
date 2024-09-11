class Solution {
public:
    int minBitFlips(int A, int  B) {
          return __builtin_popcount(A^B);
    
    }
};
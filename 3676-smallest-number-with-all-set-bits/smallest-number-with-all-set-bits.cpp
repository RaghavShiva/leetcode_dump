class Solution {
public:
    int smallestNumber(int n) {
        int b = log(n)/log(2)+1;
        return (1<<b)-1;
    }
};
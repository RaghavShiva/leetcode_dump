class Solution {
public:
    long long maxScore(int n, std::vector<std::vector<int>>& edges) {
        bool isCycle = (n == edges.size());
        
        long long nMinus1 = static_cast<long long>(n - 1);
        long long nPlus6 = static_cast<long long>(n + 6);
        long long nSquare = static_cast<long long>(n) * n;

        long long result = (nMinus1 * (nMinus1 * nPlus6 + nSquare)) / 6 + 2 * (isCycle ? 1 : 0);
        return result; }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid);

            if (count < k) low = mid + 1;
            else high = mid;
        }

        return low;
    }

private:
    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int count = 0, row = n - 1, col = 0;

        // Start from bottom-left corner
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }

        return count;
    }
};

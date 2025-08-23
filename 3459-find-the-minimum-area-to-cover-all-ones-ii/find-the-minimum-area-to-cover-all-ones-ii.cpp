class Solution {
    public:
    int calcMinArea(vector<vector<int>> &grid, int top, int bottom, int left, int right) {
        int minRow = grid.size(), maxRow = 0;
        int minCol = grid[0].size(), maxCol = 0;

        for (int row = top; row <= bottom; row++) {
            for (int col = left; col <= right; col++) {
                if (grid[row][col] == 1) {
                    minRow = min(minRow, row);
                    minCol = min(minCol, col);
                    maxRow = max(maxRow, row);
                    maxCol = max(maxCol, col);
                }
            }
        }
        return (minRow <= maxRow) ? (maxRow - minRow + 1) * (maxCol - minCol + 1)
                                  : INT_MAX / 3;
    }

    vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> rotated(cols, vector<int>(rows));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotated[cols - j - 1][i] = matrix[i][j];
            }
        }
        return rotated;
    }

    int computeMinSum(vector<vector<int>> &grid) {
        int rows = grid.size(), cols = grid[0].size();
        int minSum = rows * cols;

        // Partition into L-shapes (horizontal + vertical)
        for (int i = 0; i + 1 < rows; i++) {
            for (int j = 0; j + 1 < cols; j++) {
                minSum = min(minSum, 
                             calcMinArea(grid, 0, i, 0, cols - 1) +
                             calcMinArea(grid, i + 1, rows - 1, 0, j) +
                             calcMinArea(grid, i + 1, rows - 1, j + 1, cols - 1));

                minSum = min(minSum, 
                             calcMinArea(grid, 0, i, 0, j) +
                             calcMinArea(grid, 0, i, j + 1, cols - 1) +
                             calcMinArea(grid, i + 1, rows - 1, 0, cols - 1));
            }
        }

        // Partition into 3 horizontal strips
        for (int i = 0; i + 2 < rows; i++) {
            for (int j = i + 1; j + 1 < rows; j++) {
                minSum = min(minSum,
                             calcMinArea(grid, 0, i, 0, cols - 1) +
                             calcMinArea(grid, i + 1, j, 0, cols - 1) +
                             calcMinArea(grid, j + 1, rows - 1, 0, cols - 1));
            }
        }

        return minSum;
    }

    int minimumSum(vector<vector<int>> &grid) {
        auto rotatedGrid = rotateMatrix(grid);
        return min(computeMinSum(grid), computeMinSum(rotatedGrid));
    }
};

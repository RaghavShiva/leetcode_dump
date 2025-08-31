class Solution {
public:
    bool rows[9][10] = {false};
    bool cols[9][10] = {false};
    bool boxes[9][10] = {false};

    bool solve(vector<vector<char>>& board, int i = 0, int j = 0) {
        if (i == 9) return true; 
        if (j == 9) return solve(board, i + 1, 0);
        if (board[i][j] != '.') return solve(board, i, j + 1);

        int boxIndex = (i / 3) * 3 + j / 3;
        for (int d = 1; d <= 9; d++) {
            if (!rows[i][d] && !cols[j][d] && !boxes[boxIndex][d]) {
                board[i][j] = d + '0';
                rows[i][d] = cols[j][d] = boxes[boxIndex][d] = true;

                if (solve(board, i, j + 1)) return true;

                board[i][j] = '.';
                rows[i][d] = cols[j][d] = boxes[boxIndex][d] = false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int d = board[i][j] - '0';
                    int boxIndex = (i / 3) * 3 + j / 3;
                    rows[i][d] = cols[j][d] = boxes[boxIndex][d] = true;
                }
            }
        }
        solve(board);
    }
};

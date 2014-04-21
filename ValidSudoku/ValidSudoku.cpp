class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> cells(9, vector<bool>(9, false));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = board[i][j] - '1';
                    if (rows[i][x] || cols[j][x] || cells[(j/3)*3+i/3][x]) {
                        return false;
                    }
                    rows[i][x] = true;
                    cols[j][x] = true;
                    cells[(j/3)*3+i/3][x] = true;
                }
            }
        }
        return true;
    }
};

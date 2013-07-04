class Solution {
public:
    bool visited_cells[20][20];
    bool visited_row[20][20];
    bool visited_col[20][20];
    
    void solveSudoku(vector<vector<char>>& board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        memset(visited_cells, false, sizeof(visited_cells));  
        memset(visited_row, false, sizeof(visited_row));    
        memset(visited_col, false, sizeof(visited_col));  
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int cell = (i / 3) * 3 + j / 3;
                    int x = board[i][j] - '0';
                    visited_cells[cell][x] = true;
                    visited_row[i][x] = visited_col[j][x] = true;
                }
            }
        }
        
        isValidSudokuHelper(board, 0);
    }
    
    bool isValidSudokuHelper(vector<vector<char>>& board, int step) {
        if (step == 81) return true;
        
        int row = step / 9;
        int col = step % 9;
        int cell = (row / 3) * 3 + col / 3;
        
        if (board[row][col] != '.') {
            return isValidSudokuHelper(board, step + 1);
        }
        for (int i = 1; i <= 9; i++) {
            if (!visited_cells[cell][i] && !visited_row[row][i] && !visited_col[col][i]) {
                visited_cells[cell][i] = true;
                visited_row[row][i] = visited_col[col][i] = true;
                board[row][col] = '0' + i;
                bool flag = isValidSudokuHelper(board, step + 1);
                if (flag) return true;
                board[row][col] = '.';
                visited_cells[cell][i] = false;
                visited_row[row][i] = visited_col[col][i] = false;
            }
        }
        return false;
    }
};


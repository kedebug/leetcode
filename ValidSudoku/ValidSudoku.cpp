class Solution {
public:
    bool visited_cells[20][20];
    bool visited_row[20][20];
    bool visited_col[20][20];
    
    bool isValidSudoku(vector<vector<char>>& board) {
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
                    if (visited_cells[cell][x] || visited_row[i][x] || visited_col[j][x])
                        return false;
                    visited_cells[cell][x] = true;
                    visited_row[i][x] = visited_col[j][x] = true;
                }
            }
        }
        return true;
    }
};
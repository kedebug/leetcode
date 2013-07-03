class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        string row(n, '.');
        vector<string> queens(n, row);
        
        vector<bool> visited_col(n, false);
        vector<bool> visited_slope1(2*n-1, false);
        vector<bool> visited_slope2(2*n-1, false);
        vector<vector<bool>> visited;
        visited.push_back(visited_col);
        visited.push_back(visited_slope1);
        visited.push_back(visited_slope2);
        
        vector<vector<string>> result;
        
        generateNQueens(queens, visited, 0, n, result);
        return result;
    }
    
    void generateNQueens(vector<string>& queens, vector<vector<bool>>& visited, 
        int row, int n, vector<vector<string>>& result) {
        
        if (row == n) {
            result.push_back(queens);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (visited[0][col] == false && 
                visited[1][row+col] == false &&
                visited[2][n-1-col+row] == false) {
                
                queens[row][col] = 'Q';
                visited[0][col] = true;
                visited[1][row+col] = true;
                visited[2][n-1-col+row] = true;
                
                generateNQueens(queens, visited, row + 1, n, result);
                
                queens[row][col] = '.';
                visited[0][col] = false;
                visited[1][row+col] = false;
                visited[2][n-1-col+row] = false;
            }
        }
    }
};
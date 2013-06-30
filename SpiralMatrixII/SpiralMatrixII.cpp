
const int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}; // right, down, left, up

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n == 0) return vector<vector<int>>();
        
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int x = 0, y = -1;
        int row = n, col = n + 1;
        bool go_horizon = true;
        int i = 1, k = 0;
        while (i <= n * n) {
            int dx = dir[k%4][0];
            int dy = dir[k%4][1];
            k += 1;
            
            if (go_horizon) {
                go_horizon = false;
                col -= 1;
                for (int j = 0; j < col; j++, i++) {
                    x += dx;
                    y += dy;
                    matrix[x][y] = i;
                }
            }
            else {
                go_horizon = true;
                row -= 1;
                for (int j = 0; j < row; j++, i++) {
                    x += dx;
                    y += dy;
                    matrix[x][y] = i;
                }
            }
        }
        return move(matrix);
    }
};
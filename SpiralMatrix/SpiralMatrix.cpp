
const int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}; // right, down, left, up

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int M = matrix.size();
        if (M == 0) return vector<int>();
        int N = matrix[0].size();    
        if (N == 0) return vector<int>();
        
        vector<int> result(M * N, 0);
        int x = 0, y = -1;
        int row = M, col = N + 1;
        bool go_horizon = true;
        int i = 0, k = 0;
        while (i < M * N) {
            int dx = dir[k%4][0];
            int dy = dir[k%4][1];
            k += 1;
            
            if (go_horizon) {
                go_horizon = false;
                col -= 1;
                for (int j = 0; j < col; j++, i++) {
                    x += dx;
                    y += dy;
                    result[i] = matrix[x][y];
                }
            }
            else {
                go_horizon = true;
                row -= 1;
                for (int j = 0; j < row; j++, i++) {
                    x += dx;
                    y += dy;
                    result[i] = matrix[x][y];
                }
            }
        }
        return result;
    }
};
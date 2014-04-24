class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        int x = 0;
        int y = -1;
        int k = 0;
        int count = 0;
        int horizon = true;
        int row = n;
        int col = n + 1;
        while (count < n * n) {
            int dx = dir[k%4][0];
            int dy = dir[k%4][1];
            k++;
            if (horizon) {
                horizon = false;
                col--;
                for (int i = 0; i < col; i++) {
                    x += dx;
                    y += dy;
                    count++;
                    matrix[x][y] = count;
                }
            } else {
                horizon = true;
                row--;
                for (int i = 0; i < row; i++) {
                    x += dx;
                    y += dy;
                    count++;
                    matrix[x][y] = count;
                }
            }
        }
        return matrix;
    }
};

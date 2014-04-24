class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int row = matrix.size();
        int col = matrix[0].size() + 1;
        int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        int x = 0;
        int y = -1;
        int k = 0;
        int count = 0;
        bool horizon = true;
        while (count < matrix.size() * matrix[0].size()) {
            int dx = dir[k%4][0];
            int dy = dir[k%4][1];
            k++;
            
            if (horizon) {
                horizon = false;
                col--;
                for (int i = 0; i < col; i++, count++) {
                    x += dx;
                    y += dy;
                    result.push_back(matrix[x][y]);
                }
            } else {
                horizon = true;
                row--;
                for (int i = 0; i < row; i++, count++) {
                    x += dx;
                    y += dy;
                    result.push_back(matrix[x][y]);
                }
            }
        }
        return result;
	}
};

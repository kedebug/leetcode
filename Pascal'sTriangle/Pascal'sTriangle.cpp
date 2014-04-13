class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> triangle;
        if (numRows == 0) {
            return triangle;
        }
        triangle.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            vector<int>& prev = triangle.back();
            vector<int> row(i + 1, 0);
            row[0] = row[i] = 1;
            for (int j = 0; j < i - 1; j++) {
                row[j+1] = prev[j] + prev[j+1];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};

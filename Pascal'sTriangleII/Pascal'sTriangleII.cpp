class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> row[2];
        row[0].resize(rowIndex+1);
        row[1].resize(rowIndex+1);
        row[0][0] = 1;
        
        int T1 = 1, T2 = 0;
        for (int i = 1; i <= rowIndex; i++) {
            T1 ^= 1, T2 ^= 1;
            row[T2][0] = 1;
            for (int j = 1; j < i; j++) {
                row[T2][j] = row[T1][j-1] + row[T1][j];
            }
            row[T2][i] = 1;
        }
        return move(row[T2]);
    }
};

class Solution {
public:
    int queens;
    int mask;
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        mask = (1 << n) - 1;
        queens = 0;
        totalNQueensHelper(0, 0, 0);
        return queens;
    }
    
    void totalNQueensHelper(int col, int ld, int rd) {
        if (col != mask) {
            int valid_pos = mask & (~(col | ld | rd));
            while (valid_pos) {
                int p = valid_pos & (-valid_pos);
                valid_pos -= p;
                totalNQueensHelper(col + p, (ld + p) << 1, (rd + p) >> 1);
            }
        }
        else
            queens += 1;
    }
};
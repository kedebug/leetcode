class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        dfs(result, n, 0, 0, 0);
        return result;
    }
    
    void dfs(int& result, int n, int col, int l, int r) {
        int mask = (1 << n) - 1;
        if (col == mask) {
            result++;
        } else {
            int valid = mask & (~(col | l | r));
            while (valid) {
                int p = valid & (-valid);
                valid -= p;
                dfs(result, n, col + p, (l + p) << 1, (r + p) >> 1);
            }
        }
    }
};

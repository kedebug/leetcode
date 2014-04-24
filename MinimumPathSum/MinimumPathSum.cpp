class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
        return dp[m-1][n-1];
    }
};

// O(n) space
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        int T1 = 1;
        int T2 = 0;
        for (int i = 0; i < m; i++) {
            T1 ^= 1;
            T2 ^= 1;
            dp[T2][0] = dp[T1][0] + grid[i][0];
            for (int j = 1; j < n; j++) {
                if (i == 0) {
                    dp[T2][j] = dp[T2][j-1] + grid[i][j];
                } else {
                    dp[T2][j] = grid[i][j] + min(dp[T1][j], dp[T2][j-1]);
                }
            }
        }
        return dp[T2][n-1];
    }
};

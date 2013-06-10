class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (triangle.empty()) return 0;
        
        vector<int> dp[2];
        dp[0].resize(triangle.size());
        dp[1].resize(triangle.size());
        dp[0][0] = triangle[0][0];
        
        int T1 = 1, T2 = 0;
        for (size_t i = 1; i < triangle.size(); i++) {
            T1 ^= 1, T2 ^= 1;
            dp[T2][0] = dp[T1][0] + triangle[i][0];
            for (size_t j = 1; j <= i-1; j++) {
                dp[T2][j] = min(dp[T1][j-1], dp[T1][j]) + triangle[i][j];
            }
            dp[T2][i] = dp[T1][i-1] + triangle[i][i];
        }
        
        int result = 0x3FFFFFFF;
        for (size_t i = 0; i < dp[T2].size(); i++) {
            result = min(result, dp[T2][i]);
        }
        return result;
    }
};
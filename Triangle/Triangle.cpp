class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int level = triangle.size();
        vector<int> dp(level + 1, 0);
        for (int i = level - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};

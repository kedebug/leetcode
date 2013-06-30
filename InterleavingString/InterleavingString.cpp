class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
        int M = s1.size();
        int N = s2.size();
        
        if (M + N != s3.size()) return false;
        
        vector<vector<bool>> dp(2, vector<bool>(N + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= N; j++) {
            if (s2[j-1] == s3[j-1])
                dp[0][j] = true;
            else
                break;
        }
        int T1 = 1, T2 = 0;
        for (int i = 1; i <= M; i++) {
            T1 ^= 1, T2 ^= 1;
            dp[T2][0] = dp[T1][0] && s1[i-1] == s3[i-1];
            for (int j = 1; j <= N; j++) {
                if (s3[i+j-1] == s1[i-1] && s3[i+j-1] == s2[j-1])
                    dp[T2][j] = dp[T1][j] | dp[T2][j-1];
                else if (s3[i+j-1] == s1[i-1] && s3[i+j-1] != s2[j-1])
                    dp[T2][j] = dp[T1][j];
                else if (s3[i+j-1] != s1[i-1] && s3[i+j-1] == s2[j-1])
                    dp[T2][j] = dp[T2][j-1];
                else 
                    dp[T2][j] = false;
            }
        }
        return dp[T2][N];
    }
};
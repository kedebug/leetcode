class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int beg = 0, end = 0;
        int longest = 1;
        
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = dp[i+1][i] = true;
        }
        for (int d = 1; d < s.size(); d++) {
            for (int i = 0, j = i + d; j < s.size(); i++, j++) {
                dp[i][j] = false;
                if (s[i] == s[j]) dp[i][j] |= dp[i+1][j-1];
                if (dp[i][j] && longest < j-i+1) {
                    beg = i, end = j;
                }
            }
        }
        return s.substr(beg, end - beg + 1);
    }
private:
    static const int MAXN = 1010;
    bool dp[MAXN][MAXN];
};

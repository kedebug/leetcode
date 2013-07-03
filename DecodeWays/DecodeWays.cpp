class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s.empty()) return 0;
        
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i-1] != '0')
                dp[i] = dp[i-1];
            if (i > 1 && s[i-2] != '0') {
                int x = s[i-2] - '0';
                x = 10 * x + s[i-1] - '0';
                if (0 < x && x <= 26) 
                    dp[i] += dp[i-2];
            }
        }
        return dp[s.size()];
    }
};
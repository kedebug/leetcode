class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hash[256];
        memset(hash, -1, sizeof(hash));
        int maxlen = 0, count = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            if (hash[s[j]] == -1) {
                hash[s[j]] = j;
                maxlen = max(maxlen, j - i + 1);
            } else {
                while (i <= hash[s[j]]) {
                    hash[s[i]] = -1;
                    i += 1;
                }
                hash[s[j]] = j;
            }
        }
        return maxlen;
    }
};
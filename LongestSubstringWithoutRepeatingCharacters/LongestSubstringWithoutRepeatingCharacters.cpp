class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }
        int maxlen = 0;
        int start = 0;
        for (int limit = 0; limit < s.size(); limit++) {
            if (hash[s[limit]] != -1) {
                start = max(start, hash[s[limit]] + 1);
            }
            maxlen = max(maxlen, limit - start + 1);
            hash[s[limit]] = limit;
        }
        return maxlen;
    }
};

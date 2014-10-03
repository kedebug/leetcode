class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n = strlen(haystack);
        int m = strlen(needle);
        if (m == 0) {
            return haystack;
        }
        vector<int> next(m, -1);
        for (int i = 1, j = -1; i < m; i++) {
            while (j != -1 && needle[j+1] != needle[i]) {
                j = next[j];
            }
            if (needle[j+1] == needle[i]) {
                j++;
            }
            next[i] = j;
        }
        for (int i = 0, j = -1; i < n; i++) {
            while (j != -1 && needle[j+1] != haystack[i]) {
                j = next[j];
            }
            if (needle[j+1] == haystack[i]) {
                j++;
            }
            if (j == m - 1) {
                return haystack + i - m + 1;
            }
        }
        return NULL;
    }
};

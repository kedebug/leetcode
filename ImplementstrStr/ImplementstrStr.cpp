class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int hays_length = strlen(haystack);
        int needle_length = strlen(needle);
        
        if (hays_length == 0 && needle_length != 0)
            return NULL;
        if (hays_length == 0 || needle_length == 0) 
            return haystack;
        
        int needle_array[needle_length];
        
        getPattern(needle, needle_array, needle_length);
        int pos = KMP(haystack, hays_length, needle, needle_array, needle_length);
        if (pos != -2)
            return haystack + pos + 1;
        else
            return NULL;
    }
    
    int KMP(const char *source, int lens, const char *pattern, const int p[], int lenp) {
        int i, j = -1;
        for (i = 0; i < lens; i++) {
            while (j != -1 && source[i] != pattern[j+1])
                j = p[j];
            if (source[i] == pattern[j+1])
                j += 1;
            if (j == lenp - 1) return i - lenp;
        }
        return -2;
    }
    
    void getPattern(const char *pattern, int p[], int len) {
        p[0] = -1;
        int i, j = -1;
        for (i = 1; i < len; i++) {
            while (j != -1 && pattern[i] != pattern[j+1])
                j = p[j];
            if (pattern[i] == pattern[j+1]) 
                j += 1;
            p[i] = j;
        }
    }
};
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (s == NULL || p == NULL)
            return false;
            
        int slen = strlen(s);
        int plen = strlen(p);
        
        int count_char = 0;
        for (int i = 0; i < plen; i++) {
            if (p[i] != '*') 
                count_char += 1;
        }
        
        if (count_char > slen)
            return false;
            
        bool matches[slen + 1];
        memset(matches, false, sizeof(bool)*(slen+1));
        int first_match = 0;
        matches[first_match] = true;
        
        for (int i = 0; i < plen; i++) {
            if (i > 0 && p[i] == '*' && p[i-1] == '*')
                continue;
            if (p[i] == '*') {
                for (int j = first_match + 1; j <= slen; j++)
                    matches[j] = true;
            } else {
                int match_id = -1;
                for (int j = slen; j > first_match; j--) {
                    matches[j] = (s[j-1] == p[i] || p[i] == '?') && matches[j-1];
                    if (matches[j]) 
                        match_id = j;
                }
                if (match_id != -1) 
                    first_match = match_id;
                else
                    return false;
            }
        }
        return matches[slen];
    }
};
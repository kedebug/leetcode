class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function   

        if (s == NULL || p == NULL) 
            return false;
        if (*p == '\0') 
            return  *s == '\0';
        
        if (*(p+1) == '*') {
            //
            // notice: ".*" means repeat '.' 0 or more times
            //
            while ((*s != '\0' && *p == '.') || *s == *p) {
                if (isMatch(s, p + 2))
                    return true;
                s += 1;
            }
            return isMatch(s, p + 2);
        } 
        else if ((*s != '\0' && *p == '.') || *s == *p) {
            return isMatch(s + 1, p + 1);
        }
        return false;
    }
};

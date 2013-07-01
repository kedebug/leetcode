class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        while (*s != '\0' && *s == ' ') s += 1;
        if (*s == '\0') return false;
        
        const char *e = s + strlen(s) - 1;
        while (s <= e && *e == ' ')  e -= 1;
        
        bool is_digit = false;
        bool has_dot = false;
        bool has_exp = false;
        
        if (*s == '+' || *s == '-') s += 1;
        
        while (s <= e) {
            if ('0' <= *s && *s <= '9') {
                is_digit = true;
            }
            else if (*s == '.') {
                if (has_dot || has_exp)
                    return false;
                has_dot = true;
            }
            else if (*s == 'e') {
                if (!is_digit || has_exp)
                    return false;
                has_exp = true;
                is_digit = false;
            }
            else if (*s == '+' || *s == '-') {
                if (*(s-1) != 'e')
                    return false;
            }
            else return false;
            s += 1;
        }
        return is_digit;
    }
};
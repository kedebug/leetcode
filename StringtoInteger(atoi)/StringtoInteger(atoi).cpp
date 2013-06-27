class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (str == NULL)
            return 0;
        while (*str == ' ') {
            str++;
        }
        bool minus = false;
        if (*str == '+') {
            str++;
        } else if (*str == '-') {
            str++;
            minus = true;
        }
        long long int value = 0;
        for (; *str != '\0'; str++) {
            if ('0' <= *str && *str <= '9') {
                value *= 10;
                value += *str - '0';
            } else {
                break;
            }
        }
        if (minus)
            value = -value;
        if (value > INT_MAX)
            value = INT_MAX;
        if (value < INT_MIN)
            value = INT_MIN;
        return (int)value;
    }
};

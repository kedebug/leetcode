class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double result = 1.0;
        bool negative = false;
        if (n < 0) negative = true;
        while (n) {
            if (n & 1)
                result *= x;
            x *= x;
            n /= 2;
        }
        return negative ? (1.0 / result) : result;
    }
};
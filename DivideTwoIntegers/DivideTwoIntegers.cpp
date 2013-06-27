class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        bool signed_flag = false;
        unsigned unsigned_dividend, unsigned_divisor;
        
        if (dividend < 0) {
            unsigned_dividend = -dividend;
            signed_flag ^= true;
        } 
        else 
            unsigned_dividend = dividend;
            
        if (divisor < 0) {
            unsigned_divisor = -divisor;
            signed_flag ^= true;
        }
        else 
            unsigned_divisor = divisor;
        
        unsigned result = unsignedDivide(unsigned_dividend, unsigned_divisor);
        return signed_flag ? -result : result;
    }
    
    unsigned unsignedDivide(unsigned dividend, unsigned divisor) {
        unsigned result = 0;
        while (dividend >= divisor) {
            unsigned num = divisor;
            unsigned shift = 0;
            while (((unsigned long long)num << 1) <= dividend) {
                num <<= 1;
                shift += 1;
            }
            dividend -= num;
            result |= 1 << shift;
        }
        return result;
    }
};
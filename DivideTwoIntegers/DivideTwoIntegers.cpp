class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int divid = dividend;
        long long int divis = divisor;
        bool neg = false;
        if (divid < 0) {
            neg = neg ? false : true;
            divid = -divid;
        } 
        if (divis < 0) {
            neg = neg ? false : true;
            divis = -divis;
        }
        long long int result = 0;
        while (divid >= divis) {
            long long int x = divis;
            int shift = 0;
            while ((x << 1) <= divid) {
                x <<= 1;
                shift += 1;
            }
            result += 1 << shift;
            divid -= x;
        }
        if (neg) {
            result = -result;
        }
        return result;
    }
};

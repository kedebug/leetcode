

class Matrix {
public:
    int x00, x01;
    int x10, x11;
    Matrix() {}
    Matrix(int _x00, int _x01, int _x10, int _x11)
        : x00(_x00), x01(_x01), x10(_x10), x11(_x11) {}
    Matrix operator * (const Matrix& o) {
        Matrix m;
        m.x00 = x00 * o.x00 + x01 * o.x10;
        m.x01 = x00 * o.x01 + x01 * o.x11;
        m.x10 = x10 * o.x00 + x11 * o.x10;
        m.x11 = x10 * o.x01 + x11 * o.x11;
        return m;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return 1;
        Matrix m(1, 1, 1, 0);
        Matrix e(1, 0, 1, 0);
        while (n) {
            if (n & 1)
                e = e * m;
            m = m * m;
            n /= 2;
        }
        return e.x10;
    }
};
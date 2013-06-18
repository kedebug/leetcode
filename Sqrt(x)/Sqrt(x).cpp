class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long lf = 0;
        long long rt = x;
        while (lf <= rt) {
            long long m = (lf + rt) >> 1;
            long long sq = m * m;
            if (sq == (long long)x)
                return m;
            else if (sq < (long long)x)
                lf = m + 1;
            else 
                rt = m - 1;
        }
        return (int)rt;
    }
};
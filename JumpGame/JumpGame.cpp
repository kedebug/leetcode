class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int now = 0;
        int next = 0;
        while (now <= next) {
            next = max(next, now + A[now]);
            if (next >= n-1)
                return true;
            now += 1;
        }
        // for dynamic programming, we have below:
        // F[i] = max(F[i-1], A[i-1]) - 1;
        // if (F[i] < 0) return false;
        return false;
    }
};
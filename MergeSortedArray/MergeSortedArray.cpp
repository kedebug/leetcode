class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int end = m + n - 1;
        m -= 1;
        n -= 1;
        while (m >= 0 && n >= 0) {
            if (A[m] > B[n]) 
                A[end--] = A[m--];
            else
                A[end--] = B[n--];
        }
        while (m >= 0) 
            A[end--] = A[m--];
        while (n >= 0)
            A[end--] = B[n--];
    }
};
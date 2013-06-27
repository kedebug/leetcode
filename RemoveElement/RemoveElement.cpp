class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int low = -1, high;
        for (high = 0; high < n; high++) {
            if (A[high] != elem) {
                low += 1;
                A[low] = A[high];
            }
        }
        return low + 1;
    }
};
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n == 0) return 0;
        
        int low = 0, high;
        int count = 1;
        for (high = 1; high < n; high++) {
            if (A[low] == A[high]) {
                if (count < 2) {
                    count += 1;
                    A[++low] = A[high];
                }
            }
            else {
                A[++low] = A[high];
                count = 1;
            }
        }
        return low + 1;
    }
};
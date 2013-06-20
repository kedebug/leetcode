class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        
        int low = 0;
        for (int high = 1; high < n; high++) {
            if (A[low] != A[high]) 
                A[++low] = A[high];
        }
        return low + 1;
    }
};
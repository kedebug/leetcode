class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int lf = 0, rt = n - 1;
        while (lf <= rt) {
            int m = lf + (rt - lf) / 2;
            if (A[m] == target)
                return m;
            
            if (A[lf] <= A[m]) {
                if (A[lf] <= target && target < A[m])
                    rt = m - 1;
                else
                    lf = m + 1;
            }
            else {
                if (A[m] < target && target <= A[rt])
                    lf = m + 1;
                else
                    rt = m - 1;
            }
        }
        return -1;
    }
};
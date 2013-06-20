class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int lf = 0, rt = n - 1;
        while (lf <= rt) {
            int m = lf + (rt - lf) / 2;
            if (A[m] == target)
                return true;
            
            if (A[lf] < A[m]) {
                if (A[lf] <= target && target < A[m])
                    rt = m - 1;
                else
                    lf = m + 1;
            }
            else if (A[lf] > A[m]) {
                if (A[m] < target && target <= A[rt])
                    lf = m + 1;
                else
                    rt = m - 1;
            }
            else {
                bool onleft = search(A + lf + 1, m - lf - 1, target);
                if (onleft) return true;
                return search(A + m + 1, rt - m, target);
            } 
                
        }
        return false;
    }
};
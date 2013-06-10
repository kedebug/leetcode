class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((m + n) & 1) 
            return (double)findKth(A, m, B, n, (m+n+1)/2);
        else
            return (findKth(A, m, B, n, (m+n)/2) + findKth(A, m, B, n, (m+n)/2+1)) / 2.0;
        
    }
    
    int findKth(int A[], int m, int B[], int n, int k) {
        if (m <= 0) return B[k-1];
        if (n <= 0) return A[k-1];
        if (k <= 1) return min(A[0], B[0]);
        
        int ans;
        if (m/2 + n/2 + 1 >= k) {
            if (A[m/2] >= B[n/2])
                ans = findKth(A, m/2, B, n, k);
            else
                ans = findKth(A, m, B, n/2, k);
        } 
        else {
            if (A[m/2] >= B[n/2])
                ans = findKth(A, m, B + n/2 + 1, n - n/2 - 1, k - n/2 - 1);
            else
                ans = findKth(A + m/2 + 1, m - m/2 - 1, B, n, k - m/2 - 1);
        }
        return ans;
    }
};
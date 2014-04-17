class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) & 1) {
            return findKth((m + n - 1) / 2, A, 0, m - 1, B, 0, n - 1);
        } else {
            int x = findKth((m + n) / 2 - 1, A, 0, m - 1, B, 0, n - 1);
            int y = findKth((m + n) / 2, A, 0, m - 1, B, 0, n - 1);
            return (x + y) / 2.0;
        }
    }
    int findKth(int k, int A[], int l1, int r1, int B[], int l2, int r2) {
        if (l1 > r1) {
            return B[l2 + k];
        }
        if (l2 > r2) {
            return A[l1 + k];
        }
        int m1 = (l1 + r1) / 2;
        int m2 = (l2 + r2) / 2;
        if (A[m1] > B[m2]) {
            if (k + 1 < m1 - l1 + 1 + m2 - l2 + 1) {
                return findKth(k, A, l1, m1 - 1, B, l2, r2);
            } else {
                return findKth(k - (m2 - l2 + 1), A, l1, r1, B, m2 + 1, r2);
            }
        } else {
            if (k + 1 < m1 - l1 + 1 + m2 - l2 + 1) {
                return findKth(k, A, l1, r1, B, l2, m2 - 1);
            } else {
                return findKth(k - (m1 - l1 + 1), A, m1 + 1, r1, B, l2, r2);
            }
        }
    }
};

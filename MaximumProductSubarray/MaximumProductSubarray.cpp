class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        int result = A[0];
        int premax = A[0];
        int premin = A[0];
        for (int i = 1; i < n; i++) {
            int heremax = max(A[i], max(A[i] * premax, A[i] * premin));
            int heremin = min(A[i], min(A[i] * premax, A[i] * premin));
            result = max(result, heremax);
            premax = heremax;
            premin = heremin;
        }
        return result;
    }
};

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int maxsum = A[0];
        int tempsum = A[0];
        for (int i = 1; i < n; i++) {
            if (tempsum < 0) tempsum = 0;
            tempsum += A[i];
            maxsum = max(maxsum, tempsum);
        }
        return maxsum;
    }
};

// 
// solution 2 : divide and conquer
//
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return maxSubArray(A, 0, n - 1);
    }
    
    int maxSubArray(int A[], int left, int right) {
        if (left > right)
            return INT_MIN;
        
        int mid = (left + right) / 2;
        int lmax = maxSubArray(A, left, mid - 1);
        int rmax = maxSubArray(A, mid + 1, right);
        
        int sum = 0, mlmax = 0;
        for (int i = mid - 1; i >= left; i--) {
            sum += A[i];
            mlmax = max(mlmax, sum);
        }
        sum = 0;
        int mrmax = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += A[i];
            mrmax = max(mrmax, sum);
        }
        
        return max(mlmax + A[mid] + mrmax, max(lmax, rmax));
    }
};
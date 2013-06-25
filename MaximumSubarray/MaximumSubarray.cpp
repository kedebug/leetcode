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
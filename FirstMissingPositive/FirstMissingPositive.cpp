class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int i = 0;
        while (i < n) {
            if (A[i] != i + 1 && 0 < A[i] && A[i] <= n && A[A[i]-1] != A[i])
                swap(A[i], A[A[i]-1]);
            else
                i += 1;
        }
        int first_positive = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                first_positive = i + 1;
                break;
            }
        }
        if (first_positive == 0)
            first_positive = n + 1;
        return first_positive;
    }
};

//
// solution 2
//
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        bool find_1 = false;
        for (int i = 0; i < n; i++) {
            if (A[i] == 1)
                find_1 = true;
            else if (A[i] <= 0)
                A[i] = 1;
        }
        if (!find_1) return 1;
        for (int i = 0; i < n; i++) {
            if (A[i] > 0 && A[i] <= n && A[A[i]-1] > 0) {
                A[A[i]-1] = -A[A[i]-1];
            }
            else if (A[i] <= -1 && -A[i] <= n && A[-A[i]-1] > 0)
                A[-A[i]-1] = -A[-A[i]-1];
        }
        int first_positive = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > 0) {
                first_positive = i + 1;
                break;
            }
        }
        if (first_positive == 0)
            first_positive = n + 1;
        return first_positive;
    }
};
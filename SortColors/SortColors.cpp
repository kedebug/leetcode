
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int low = 0, high = n - 1;
        int mid = 0;
        
        while (mid <= high) {
            if (A[mid] == 0) {
                A[mid++] = A[low];
                A[low++] = 0;
            }
            else if (A[mid] == 1) {
                mid += 1;
            }
            else if (A[mid] == 2) {
                A[mid] = A[high];
                A[high--] = 2;
            }
        }
    }
};

//
// Solution2 using the method like quicksort
//
class Solution2 {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int p = split(A, 0, n - 1, 0);
        split(A, p + 1, n - 1, 1);
    }
    int split(int A[], int low, int high, int pivot) {
        int i = low - 1;
        for (int j = low; j <= high; j++) {
            if (A[j] <= pivot) {
                i += 1;
                if (i != j) swap(A[i], A[j]);
            }
        }
        return i;
    }
};
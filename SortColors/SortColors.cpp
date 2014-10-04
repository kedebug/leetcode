class Solution {
public:
    void sortColors(int A[], int n) {
        int p0 = -1;
        int p1 = 0;
        int p2 = n;
        while (p1 < p2) {
            if (A[p1] == 1) {
                p1++;
            } else if (A[p1] == 0) {
                swap(A[p0+1], A[p1]);
                p0++;
                p1++;
            } else {
                swap(A[p1], A[p2-1]);
                p2--;
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

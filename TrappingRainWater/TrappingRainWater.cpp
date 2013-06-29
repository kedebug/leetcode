class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int max_from_left[n];
        int max_from_right[n];
        
        max_from_left[0] = A[0];
        for (int i = 1; i < n; i++)
            max_from_left[i] = max(max_from_left[i-1], A[i]);
        
        max_from_right[n-1] = A[n-1];
        for (int i = n - 2; i >= 0; i--)
            max_from_right[i] = max(max_from_right[i+1], A[i]);
            
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            int min_height = min(max_from_left[i-1], max_from_right[i+1]);
            if (min_height > A[i])
                water += min_height - A[i];
        }
        return water;
    }
};
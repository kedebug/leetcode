class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> range;
        range.push_back(find_lower_bound(A, n, target));
        range.push_back(find_upper_bound(A, n, target));
        return range;
    }
    
    int find_lower_bound(int A[], int n, int target) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] >= target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (A[left] == target)
            return left;
        return -1;
    }
    
    int find_upper_bound(int A[], int n, int target) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (A[right] == target)
            return right;
        return -1;
    }
};
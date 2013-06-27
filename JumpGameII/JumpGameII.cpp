class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int begin = 0, end = 0;
        int min_step = 0;
        int max_next = 0;
        
        while (end < n - 1) {
            min_step += 1;
            for (int i = begin; i <= end; i++)
                max_next = max(max_next, i + A[i]);
            if (max_next <= end) 
                return -1;
            begin = end + 1;
            end = max_next;
        }
        return min_step;
    }
};
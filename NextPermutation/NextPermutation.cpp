class Solution {
public:
    void nextPermutation(vector<int>& num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = num.size();
        if (n <= 1) return;
        
        bool found = false;
        int i, p, maxval = INT_MIN;
        for (i = n - 1; i >= 1; i--) {
            if (maxval < num[i]) {
                maxval = num[i];
            }
            if (num[i-1] < maxval) {
                int delta = INT_MAX;
                for (int j = i; j < n; j++) {
                    if (num[j] > num[i-1] && num[j] - num[i-1] < delta)
                        p = j;
                }
                found = true; 
                break;
            }
        }
        if (!found) {
            reverse(num.begin(), num.end());
        }
        else {
            swap(num[p], num[i-1]);
            sort(num.begin() + i, num.end());
        }
    }
};
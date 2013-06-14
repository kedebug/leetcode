class Solution {
public:
    int threeSumClosest(vector<int>& num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int n = num.size();
        int closet = INT_MAX;
        int result;
        for (int i = 0; i < n; i++) {
            int lf = i + 1;
            int rt = n - 1;
            while (lf < rt) {
                int sum = num[i] + num[lf] + num[rt];
                if (sum == target) {
                    return target;
                }
                else if (sum < target) {
                    if (target - sum < closet) {
                        result = sum;
                        closet = target - sum;
                    }
                    lf += 1;
                }
                else {
                    if (sum - target < closet) {
                        result = sum;
                        closet = sum - target;
                    }
                    rt -= 1;
                }
            }
        }
        return result;
    }
};
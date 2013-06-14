class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        sort(num.begin(), num.end());
        int n = num.size();
        for (int i = 0; i < n; i++) {
            int lf = i + 1;
            int rt = n - 1;
            while (lf < rt) {
                int sum = num[i] + num[lf] + num[rt];
                if (sum < 0) {
                    lf += 1;
                }
                else if (sum > 0) {
                    rt -= 1;
                }
                else {
                    vector<int> elem;
                    elem.push_back(num[i]);
                    elem.push_back(num[lf]);
                    elem.push_back(num[rt]);
                    if (find(result.begin(), result.end(), elem) == result.end())
                        result.push_back(elem);
                    lf += 1;
                    rt -= 1;
                }
            }
        }
        return move(result);
    }
};
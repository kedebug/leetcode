class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        if (num.empty()) {
            return result;
        }
        sort(num.begin(), num.end());
        for (int start = 0; start < num.size(); start++) {
            int i = start + 1;
            int j = num.size() - 1;
            int target = -num[start];
            while (i < j) {
                if (num[i] + num[j] == target) {
                    vector<int> triple;
                    triple.push_back(num[start]);
                    triple.push_back(num[i]);
                    triple.push_back(num[j]);
                    result.push_back(triple);
                    while (i + 1 < num.size() && num[i] == num[i+1]) {
                        i++;
                    }
                    while (j - 1 >= 0 && num[j] == num[j-1]) {
                        j--;
                    }
                    i++;
                    j--;
                } else if (num[i] + num[j] < target) {
                    i++;
                } else {
                    j--;
                }
            }
            while (start + 1 < num.size() && num[start] == num[start+1]) {
                start++;
            }
        }
        return result;
    }
};

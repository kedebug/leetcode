class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> result;
        sort(num.begin(), num.end());
        do {
            result.push_back(num);
        } while (getNext(num));
        return result;
    }
    
    bool getNext(vector<int>& num) {
        int i = num.size() - 1;
        while (i >= 1 && num[i-1] >= num[i]) {
            i--;
        }
        if (i == 0) {
            return false;
        }
        int j = num.size() - 1;
        while (j >= i) {
            if (num[j] > num[i-1]) {
                break;
            }
            j--;
        }
        swap(num[i-1], num[j]);
        reverse(num.begin() + i, num.end());
        return true;
    }
};

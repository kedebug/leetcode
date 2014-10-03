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

// recursive solution
class Solution {
public:
    void helper(vector<vector<int>>& result, vector<int>& num, int x) {
        if (x == num.size()) {
            result.push_back(num);
            return;
        }
        helper(result, num, x + 1);
        map<int, bool> hash;
        hash[num[x]] = true;
        for (int i = x + 1; i < num.size(); i++) {
            if (hash[num[i]]) {
                continue;
            }
            hash[num[i]] = true;
            swap(num[x], num[i]);
            helper(result, num, x + 1);
            swap(num[x], num[i]);
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        helper(result, num, 0);
        return move(result);
    }
};

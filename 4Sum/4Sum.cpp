
struct twoSum {
    int lf, rt, val;
    twoSum(int _lf, int _rt, int _val)
        : lf(_lf), rt(_rt), val(_val) { }
    friend bool operator < (const twoSum& lhs, const twoSum& rhs) {
        return lhs.val < rhs.val;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        vector<twoSum> twosums;
        for (int i = 0; i < num.size(); i++) {
            for (int j = i + 1; j < num.size(); j++)
                twosums.push_back(twoSum(i, j, num[i]+num[j]));
        }
        sort(twosums.begin(), twosums.end());
        
        int n = twosums.size();
        for (int i = 0; i < n; i++) {
            int value = target - twosums[i].val;
            int lf = find_lower_bound(twosums, i + 1, n - 1, value);
            int rt = find_upper_bound(twosums, i + 1, n - 1, value);
            for (int j = lf; j <= rt; j++) {
                if (twosums[i].lf == twosums[j].lf) continue;
                if (twosums[i].rt == twosums[j].lf) continue;
                if (twosums[i].lf == twosums[j].rt) continue;
                if (twosums[i].rt == twosums[j].rt) continue;
                vector<int> four;
                four.push_back(num[twosums[i].lf]);
                four.push_back(num[twosums[i].rt]);
                four.push_back(num[twosums[j].lf]);
                four.push_back(num[twosums[j].rt]);
                sort(four.begin(), four.end());
                if (find(result.begin(), result.end(), four) == result.end())
                    result.push_back(four);
            }
        }
        return move(result);
    }
    int find_lower_bound(vector<twoSum>& twosums, int l, int r, int val) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (twosums[m].val >= val)
                r = m - 1;
            else
                l = m + 1;
        }
        return r + 1;
    }
    int find_upper_bound(vector<twoSum>& twosums, int l, int r, int val) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (twosums[m].val <= val)
                l = m + 1;
            else
                r = m - 1;
        }
        return l - 1;
    }
};
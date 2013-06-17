class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int>> result;
        
        do {
            result.push_back(num);
            nextPermutation(num);
        } while (!isEqual(result[0], num));
        
        return move(result);    
    }
    
    bool isEqual(vector<int>& n1, vector<int>& n2) {
        if (n1.size() != n2.size())
            return false;
        for (int i = 0; i < n1.size(); i++) {
            if (n1[i] != n2[i]) return false;
        }
        return true;
    }
    
    void nextPermutation(vector<int>& num) {
        int lf = num.size() - 2;
        while (lf >= 0 && num[lf] >= num[lf+1])
            lf -= 1;
        if (lf == -1) {
            reverse(num.begin(), num.end());
            return;
        }
        int rt = num.size() - 1;
        while (rt > lf && num[rt] <= num[lf])
            rt -= 1;
        swap(num[lf], num[rt]);
        reverse(num.begin() + lf + 1, num.end());
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string common;
        if (strs.size() == 0)
            return common;
        common = strs[0];
        for (size_t i = 1; i < strs.size(); i++) {
            size_t j;
            for (j = 0; j < common.size(); j++) {
                if (common[j] != strs[i][j]) break;
            }
            if (j == 0) {
                common = "";
                return common;
            }
            else common = common.substr(0, j);
        }
        return common;
    }
};
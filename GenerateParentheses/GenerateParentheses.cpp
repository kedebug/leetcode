class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        if (n == 0) {
            return result;
        }
        dfs(result, s, n, n);
        return result;
    }
    void dfs(vector<string>& result, string& s, int left, int right) {
        if (left > right) {
            return;
        }
        if (left == 0 && right == 0) {
            result.push_back(s);
            return;
        }
        if (left >= 1) {
            s.push_back('(');
            dfs(result, s, left - 1, right);
            s.pop_back();
        }
        if (right >= 1) {
            s.push_back(')');
            dfs(result, s, left, right - 1);
            s.pop_back();
        }
    }
};

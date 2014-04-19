class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, string> keypad;
        keypad[2] = string("abc");
        keypad[3] = string("def");
        keypad[4] = string("ghi");
        keypad[5] = string("jkl");
        keypad[6] = string("mno");
        keypad[7] = string("pqrs");
        keypad[8] = string("tuv");
        keypad[9] = string("wxyz");
        
        vector<string> result;
        string letter;
        dfs(result, letter, digits, 0, keypad);
        return result;
    }
    void dfs(vector<string>& result, string& letter, string& digits, int pos, map<int, string>& keypad) {
        if (pos == digits.size()) {
            result.push_back(letter);
            return;
        }
        int x = digits[pos] - '0';
        string s = keypad[x];
        for (int i = 0; i < s.size(); i++) {
            letter.push_back(s[i]);
            dfs(result, letter, digits, pos + 1, keypad);
            letter.pop_back();
        }
    }
};

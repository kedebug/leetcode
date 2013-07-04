
const string Solution::keypad[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    static const string keypad[8];
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> all_letters;
        string letter;
        letterCombinationsHelper(digits, 0, letter, all_letters);
    }
    void letterCombinationsHelper(string& digits, int step, string& letter, vector<string>& all_letters) {
        if (step == digits.size()) {
            all_letters.push_back(letter);
            return;
        }
        int x = digits[step] - '2';
        for (int i = 0; i < keypad[x].size(); i++) {
            letter += keypad[x][i];
            letterCombinationsHelper(digits, step + 1, letter, all_letters);
            letter.erase(letter.size() - 1, 1);
        }
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        string alphas;
        
        for (size_t i = 0; i < s.size(); i++) {
            if ('A' <= s[i] && s[i] <= 'Z') 
                alphas += s[i] - 'A' + 'a';
            else if ('a' <= s[i] && s[i] <= 'z')
                alphas += s[i];
            else if ('0' <= s[i] && s[i] <= '9')
                alphas += s[i];
        }
        
        if (alphas.size() == 0)
            return true;
            
        size_t beg = 0, end = alphas.size() - 1;
        
        while (beg < end) {
            if (alphas[beg] == alphas[end]) {
                beg += 1;
                end -= 1;
            } else {
                return false;
            }
        }
        return true;
    }
};

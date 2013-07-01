class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return isScrambleHelper(s1, 0, s2, 0, s1.size());
    }
    
    bool isScrambleHelper(string& s1, int l1, string& s2, int l2, int size) {
        if (!canScramble(s1, l1, s2, l2, size)) return false;     
        if (size == 1) return true;
        
        for (int i = 1; i < size; i++) {
            if (isScrambleHelper(s1, l1, s2, l2 + size - i, i) &&
                isScrambleHelper(s1, l1 + i, s2, l2, size - i))
                return true;
            if (isScrambleHelper(s1, l1, s2, l2, i) && 
                isScrambleHelper(s1, l1 + i, s2, l2 + i, size - i))
                return true;
        }
        return false;
    }
    
    bool canScramble(string& s1, int l1, string& s2, int l2, int size) {
        int hash[26] = {0};
        for (int i = 0; i < size; i++) {
            hash[s1[l1 + i] - 'a'] += 1;
            hash[s2[l2 + i] - 'a'] -= 1;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i]) return false;
        }
        return true;
    }
};
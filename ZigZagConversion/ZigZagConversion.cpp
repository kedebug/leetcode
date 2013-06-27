class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
        if (nRows == 1) return s;
        string result;
        if (s.size() == 0) return result;

        int delta = nRows*2-2;
        for (int i = 0; i < nRows; i++) {
            for (int j = i; j < s.size(); j += delta) {
                result += s[j];
                if (i == 0 || i == nRows-1) continue;
                if (j + (nRows-i-1)*2 < s.size())
                    result += s[j+(nRows-i-1)*2];
            }
        }
        return result;
    }
};

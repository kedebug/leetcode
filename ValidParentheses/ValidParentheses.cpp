class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = s.size();
        char stack[n];
        int size = 0;
        int hash[256];
        
        hash['('] = 0, hash['{'] = 1, hash['['] = 2;
        hash[')'] = 3, hash['}'] = 4, hash[']'] = 5;
        
        
        for (int i = 0; i < n; i++) {
            if (hash[s[i]] < 3)
                stack[size++] = s[i];
            else {
                if (size == 0) return false;
                if ((hash[s[i]] % 3) != hash[stack[size-1]]) return false;
                size -= 1;
            }
        }
        return size ? false : true;
    }
};
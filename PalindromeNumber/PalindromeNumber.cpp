class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (x < 0) return false;
        
        int base = 1;
        while (x / base >= 10) {
            base *= 10;
        }
        while (x) {
            if (x / base != x % 10)
                return false;
            x = (x % base) / 10;
            base /= 100;
        }
        return true;
    }
};

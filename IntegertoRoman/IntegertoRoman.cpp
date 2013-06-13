class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        char symbol[] = {'I', 'V', 'X', 'L','C', 'D', 'M'};
        string result;
        int base = 1000;
        int d = 6;
        while (num) {
            int digit = num / base;
            appendRoman(digit, result, symbol + d);
            d -= 2;
            num %= base;
            base /= 10;
        }
        return result;
    }
    
    void appendRoman(int n, string& s, char symbol[]) {
        assert(n <= 9);
        
        if (n == 0) return;
        if (n <= 3) {
            s.append(n, symbol[0]);
        }
        else if (n == 4) {
            s.append(1, symbol[0]);
            s.append(1, symbol[1]);
        }
        else if (n <= 8) {
            s.append(1, symbol[1]);
            s.append(n - 5, symbol[0]);
        }
        else if (n == 9) {
            s.append(1, symbol[0]);
            s.append(1, symbol[2]);
        }
    }
};
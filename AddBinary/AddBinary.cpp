class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        string c;
        int len_a = a.size();
        int len_b = b.size();
        int carry = 0;
        for (int i = 0; i < min(len_a, len_b); i++) {
            int x = a[len_a - i - 1] - '0';
            int y = b[len_b - i - 1] - '0';
            c += (x + y + carry) % 2 + '0';
            carry = (x + y + carry) / 2;
        }
        if (len_a > len_b) {
            for (int i = len_b; i < len_a; i++) {
                int x = a[len_a - i - 1] - '0';
                c += (x + carry) % 2 + '0';
                carry = (x + carry) / 2;
            }
        }
        else if (len_a < len_b) {
            for (int i = len_a; i < len_b; i++) {
                int x = b[len_b - i - 1] - '0';
                c += (x + carry) % 2 + '0';
                carry = (x + carry) / 2;
            }
        }
        while (carry) {
            c += carry % 2 + '0';
            carry /= 2;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int i = 0;
        while (i < a.size() && i < b.size()) {
            carry += a[i] - '0' + b[i] - '0';
            c += carry % 2 + '0';
            carry /= 2;
            i++;
        }
        while (i < a.size()) {
            carry += a[i] - '0';
            c += carry % 2 + '0';
            carry /= 2;
            i++;
        }
        while (i < b.size()) {
            carry += b[i] - '0';
            c += carry % 2 + '0';
            carry /= 2;
            i++;
        }
        while (carry) {
            c += carry % 2 + '0';
            carry /= 2;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};

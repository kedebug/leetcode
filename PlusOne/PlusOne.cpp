class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int carry = 0;
        int size = digits.size();
        digits[size-1] += 1;
        
        for (int i = size - 1; i >= 0; i--) {
            int val = digits[i];
            digits[i] = (val + carry) % 10;
            carry = (val + carry) / 10;
            if (carry == 0) break;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
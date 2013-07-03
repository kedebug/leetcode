class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> gray_code;
        for (int i = 0; i < (1 << n); i++)
            gray_code.push_back((i >> 1) ^ i);
        return gray_code;
    }
};
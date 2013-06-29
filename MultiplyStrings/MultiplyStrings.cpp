class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len_num1 = num1.size();
        int len_num2 = num2.size();
        
        vector<int> multiply_num(len_num1 + len_num2, 0);
        
        for (int i = len_num1 - 1; i >= 0; i--) {
            for (int j = len_num2 - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int pa = len_num1 - i - 1;
                int b = num2[j] - '0';
                int pb = len_num2 - j - 1;
                multiply_num[pa + pb] += a * b;
            }
        }
        for (int i = 0; i < multiply_num.size(); i++) {
            if (multiply_num[i] > 0) {
                multiply_num[i+1] += multiply_num[i] / 10;
                multiply_num[i] = multiply_num[i] % 10;
            }
        }
        
        while (multiply_num[multiply_num.size()-1] == 0)
            multiply_num.pop_back();
        
        string num;
        for (auto iter = multiply_num.rbegin(); iter != multiply_num.rend(); iter++)
            num += (char)(*iter + '0');
        
        if (num.empty())
            num = "0";
        
        return num;
    }
};
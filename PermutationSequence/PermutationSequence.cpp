
const int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //
        // http://zh.wikipedia.org/wiki/%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80
        //
        string sequence;
        bool hash[12];
        memset(hash, false, sizeof(hash));
        k -= 1;
        for (int i = n; i >= 1; i--) {
            int x = k / factorial[i-1];
            int count = 0;
            for (int j = 1; j <= n; j++) {
                if (!hash[j]) count += 1;
                if (count == x + 1) {
                    x = j;
                    break;
                }
            }
            k %= factorial[i-1];
            hash[x] = true;
            sequence += x + '0'; 
        }
        return sequence;
    }
};
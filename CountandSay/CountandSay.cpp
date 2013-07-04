class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        string begin = "1";
        for (int i = 0; i < n - 1; i++) {
            string next;
            int start = 0;
            while (start < begin.size()) {
                int end = start;
                int count = 0;
                while (end < begin.size() && begin[start] == begin[end]) {
                    end += 1;
                    count += 1;
                }
                next += char('0' + count);
                next += begin[start];
                start = end;
            }
            begin = next;
        }
        return begin;
    }
};
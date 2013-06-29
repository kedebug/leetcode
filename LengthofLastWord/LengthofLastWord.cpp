class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int last_word_length = 0;
        int word_length = 0;
        while (*s != '\0') {
            while (*s == ' ')
                s++;
            
            int word_length = 0;
            while (*s != ' ' && *s != '\0') {
                s++;
                word_length += 1;
            }
            if (word_length)
                last_word_length = word_length;
        }
        return last_word_length;
    }
};
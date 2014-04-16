class Solution {
public:
    void reverseWords(string &s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        while (j >= 0 && s[j] == ' ') {
            j--;
        }

        s = s.substr(i, j - i + 1);
        reverse(s, 0, s.size() - 1);
        
        for (i = 0, j = 0; j < s.size(); j++) {
            if (s[j] == ' ') {
                s[i++] = ' ';
                while (j+1 < s.size() && s[j+1] == ' ') {
                    j++;
                }
            } else {
                s[i++] = s[j];
            }
        }
        s = s.substr(0, i);
        for (i = 0, j = 0; j < s.size(); j++) {
            if (s[j] == ' ') {
                reverse(s, i, j - 1);
                i = j + 1;
            }
        }
        
        if (i < s.size()) {
            reverse(s, i, s.size() - 1);
        }
    }
    
    void reverse(string& s, int i, int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

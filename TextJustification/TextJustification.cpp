class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> needed_lines(words.size(), 0);
        int count_line = 1;
        int len = 0;
        for (int i = 0; i < words.size(); i++) {
            if (len + words[i].size() + 1 <= L + 1) {
                needed_lines[i] = count_line;
                len += words[i].size() + 1;
            }
            else {
                count_line += 1;
                len = words[i].size() + 1;
                needed_lines[i] = count_line;
            }
        }
        vector<string> justified;
        int start = 0;
        
        while (start < words.size()) {
            int end = start + 1;
            int words_len = words[start].size();
            while (end < words.size() && needed_lines[start] == needed_lines[end]) {
                words_len += words[end].size();
                end += 1;
            }
            int words_num = end - start;
            string justified_line;
            if (words_num == 1) {
                justified_line += words[start];
                justified_line.append(L - words_len, ' ');
            }
            else {
                int extra = (L - words_len) % (words_num - 1);
                int blank = (L - words_len) / (words_num - 1);
                if (end == words.size()) {
                    extra = 0; blank = 1;
                }
                for (int i = start; i < end; i++) {
                    justified_line += words[i];
                    if (i == end -1) continue;
                    if (extra > 0) {
                        justified_line.append(blank + 1, ' ');
                        extra -= 1;
                    }
                    else
                        justified_line.append(blank, ' ');
                }
                if (end == words.size()) {
                    justified_line.append(L - words_len - words_num + 1, ' ');
                }
            }
            justified.push_back(justified_line);
            start = end;
        }
        return justified;
    }
};
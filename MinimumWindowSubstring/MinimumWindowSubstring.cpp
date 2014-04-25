class Solution {
public:
    string minWindow(string S, string T) {
        string result("");
        map<char, int> needed;
        map<char, int> found;
        for (int i = 0; i < T.size(); i++) {
            needed[T[i]]++;
        }
        int count = 0;
        int minlen = S.size() + 1;
        for (int i = 0, j = 0; j < S.size(); j++) {
            if (needed[S[j]] == 0) {
                continue;
            }
            found[S[j]]++;
            if (found[S[j]] <= needed[S[j]]) {
                count++;
            }
            if (count == T.size()) {
                while (i <= j) {
                    if (found[S[i]] == 0) {
                        i++;
                    } else if (found[S[i]] > needed[S[i]]) {
                        found[S[i]]--;
                        i++;
                    } else {
                        break;
                    }
                }
                if (minlen > j - i + 1) {
                    minlen = j - i + 1;
                    result = S.substr(i, minlen);
                }
            }
        }
        return result;
    }
};

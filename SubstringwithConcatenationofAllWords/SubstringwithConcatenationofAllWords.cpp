class Solution {
public:
    // 1612ms
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int M = L.size();
        int N = L[0].size();
        
        vector<int> indices;
        if (S.size() < M * N) return indices;
        
        map<string, int> words_dict;
        for (int i = 0; i < M; i++)
            words_dict[L[i]] += 1;
            
        for (int i = 0; i <= S.size() - M*N; i++) {
            map<string, int> has_found;
            bool flag = true;
            for (int j = 0; j < M; j++) {
                string sub_string = S.substr(i + j * N, N);
                if (words_dict.find(sub_string) == words_dict.end()) {
                    flag = false; break;
                }
                has_found[sub_string] += 1;
                if (has_found[sub_string] > words_dict[sub_string]) {
                    flag = false; break;
                }
            }
            if (flag) indices.push_back(i);
        }
        return indices;
    }
};

//
// Solution2 : 1356ms
//
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int M = L.size();
        int N = L[0].size();
        
        vector<int> indices;
        if (S.size() < M * N) return indices;
        
        map<string, int> words_dict;
        for (int i = 0; i < M; i++)
            words_dict[L[i]] += 1;
            
        for (int i = 0; i < N; i++) {
            vector<string> substrings;
            for (int j = i; j + N <= S.size(); j += N)
                substrings.push_back(S.substr(j, N));
            for (int j = 0; j + M <= substrings.size(); j++) {
                map<string, int> has_found;
                bool flag = true;
                for (int k = 0; k < M; k++) {
                    if (words_dict.find(substrings[j+k]) == words_dict.end()) {
                        flag = false; break;
                    }
                    has_found[substrings[j+k]] += 1;
                    if (has_found[substrings[j+k]] > words_dict[substrings[j+k]]) {
                        flag = false; break;
                    }
                }
                if (flag) indices.push_back(i + j * N);
            }
        }
        return indices;
    }
};
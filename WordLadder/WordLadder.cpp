class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        queue<pair<string, int>> Q;
        unordered_set<string> visited;
        Q.push(make_pair(start, 1));
        
        while (!Q.empty()) {
            pair<string, int> src = Q.front();
            Q.pop();
            if (src.first == end) {
                return src.second;
            }
            vector<string> neighbor;
            getNeighbors(src.first, neighbor, dict);
            for (string word : neighbor) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    Q.push(make_pair(word, src.second + 1));
                }
            } 
        }
        return 0;
    }

    void getNeighbors(const string& word, 
        vector<string>& neighbor, 
        const unordered_set<string>& dict) {
            for (size_t i = 0; i < word.size(); i++) {
                string copyword(word);
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    copyword[i] = ch;
                    if (dict.find(copyword) != dict.end()) {
                        neighbor.push_back(copyword);
                    }
                }
            }
    }
};

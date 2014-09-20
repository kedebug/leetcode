class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, int> exists;
        for (int i = 0; i < strs.size(); i++) {
            string u = strs[i];
            sort(u.begin(), u.end());
            if (exists.find(u) == exists.end()) {
                exists[u] = i;
            } else {
                if (exists[u] >= 0) {
                    result.push_back(strs[exists[u]]);
                    exists[u] = -1;
                }
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};

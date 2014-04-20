class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        if (L.empty()) {
            return result;
        }
        int n = L.size();
        int len = L[0].size();
        map<string, int> hash;
        for (int i = 0; i < n; i++) {
            hash[L[i]] += 1;
        }
        for (int i = 0; i < len; i++) {
            vector<string> slices;
            for (int j = i; j + len <= S.size(); j += len) {
                slices.push_back(S.substr(j, len));
            }
            for (int j = 0; j + n <= slices.size(); j++) {
                map<string, int> found;
                for (int k = 0; k < n; k++) {
                    found[slices[j+k]] += 1;
                    if (found[slices[j+k]] > hash[slices[j+k]]) {
                        break;
                    }
                    if (k == n - 1) {
                        result.push_back(i + j * len);
                    }
                }
            }
        }
        return result;
    }
};

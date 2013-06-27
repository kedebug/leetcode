class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        map<string, vector<int>> dict;
        
        for (int i = 0; i < strs.size(); i++) {
            string copy_string(strs[i]);
            sort(copy_string.begin(), copy_string.end());
            dict[copy_string].push_back(i);
        }
        
        vector<string> anagrams;
        for (auto iter = dict.begin(); iter != dict.end(); iter++) {
            vector<int>& string_id = iter->second;
            if (string_id.size() <= 1) continue;
            for (int i = 0; i < string_id.size(); i++)
                anagrams.push_back(strs[string_id[i]]);
        }
        
        return move(anagrams);
    }
};
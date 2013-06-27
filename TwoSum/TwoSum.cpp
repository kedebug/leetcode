bool lessthan(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    if (lhs.first == rhs.first) 
        return lhs.second < rhs.second;
    return lhs.first < rhs.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<pair<int, int>> vnum;
        for (size_t i = 0; i < numbers.size(); i++) {
            vnum.push_back(make_pair(numbers[i], i + 1));
        }
        sort(vnum.begin(), vnum.end(), lessthan);
        vector<int> ans;
        int s = 0, e = vnum.size() - 1;
        while (s < e) {
            if (vnum[s].first + vnum[e].first == target) {
                ans.push_back(min(vnum[s].second, vnum[e].second));
                ans.push_back(max(vnum[s].second, vnum[e].second));
                break;
            } 
            else if (vnum[s].first + vnum[e].first > target)
                e -= 1;
            else 
                s += 1;
        }
        return ans;
    }
};

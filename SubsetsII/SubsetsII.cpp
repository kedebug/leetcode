class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        vector<vector<int>> subsets;
        vector<int> integers;
        
        if (S.empty()) return subsets;
        
        sort(S.begin(), S.end());
        DFS(integers, 0, S, subsets);
        
        return move(subsets);
    }
    
    void DFS(vector<int>& integers, int start, vector<int>& S, vector<vector<int>>& subsets) {
        if (start == S.size()) {
            subsets.push_back(integers);
            return;
        }
        int end = start;
        while (end + 1 < S.size() && S[start] == S[end+1])
            end += 1;
        
        DFS(integers, end + 1, S, subsets);
        
        for (int i = start; i <= end; i++) {
            integers.push_back(S[i]);
            DFS(integers, end + 1, S, subsets);
        }
        for (int i = start; i <= end; i++)
            integers.pop_back();
    }
};
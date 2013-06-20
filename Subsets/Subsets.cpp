class Solution {
public:
    vector<vector<int> > subsets(vector<int>& S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int>> result;
        vector<int> subset;
        
        sort(S.begin(), S.end());
        DFS(subset, 0, S, result);
        return move(result);
    }
    
    void DFS(vector<int>& subset, int step, vector<int>& S, vector<vector<int>>& result) {
        if (step == S.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(S[step]);
        DFS(subset, step + 1, S, result);
        subset.pop_back();
        
        DFS(subset, step + 1, S, result);
    }
};
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int>> result;
        vector<int> comb;
        DFS(comb, 0, 0, k, n, result);
        return move(result);
    }
    
    void DFS(vector<int>& comb, int step, int p, int k, int n, vector<vector<int>>& result) {
        if (step == k) {
            result.push_back(comb);
            return;
        }
        if (n - p < k - step) 
            return;
        
        comb.push_back(p + 1);
        DFS(comb, step + 1, p + 1, k, n, result);
        comb.pop_back();
        
        DFS(comb, step, p + 1, k, n, result);
    }
};
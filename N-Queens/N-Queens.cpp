class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> result;
        if (n == 0) {
            return result;
        }
        vector<string> sol(n, string(n, '.'));
        vector<vector<bool>> visited(3, vector<bool>(2*n, false));
        dfs(result, sol, visited, 0);
        return result;
    }
    
    void dfs(vector<vector<string>>& result, vector<string>& sol,  vector<vector<bool>>& visited, int row) {
        int n = sol.size();
        if (row == n) {
            result.push_back(sol);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (visited[0][col] || visited[1][row+col] || visited[2][n-1-row+col]) {
                continue;
            }
            visited[0][col] = true;
            visited[1][row+col] = true;
            visited[2][n-1-row+col] = true;
            sol[row][col] = 'Q';
            dfs(result, sol, visited, row + 1);
            sol[row][col] = '.';
            visited[0][col] = false;
            visited[1][row+col] = false;
            visited[2][n-1-row+col] = false;
        }
    }
};

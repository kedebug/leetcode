class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        this->word = word;
        row = board.size();
        if (row == 0) return false;
        col = board[0].size();
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                map[i][j] = board[i][j];
                visited[i][j] = false;
            }
        }
        bool flag = false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (map[i][j] == word[0]) {
                    visited[i][j] = true;
                    flag = DFS(i, j, 1);
                    visited[i][j] = false;
                    if (flag) return flag;
                }
            }
        }
        return false;
    }
    
private:
    bool isValid(int x, int y) {
        if (0 <= x && x < row && 0 <= y && y < col) {
            return true;
        }
        return false;
    }
    
    bool DFS(int x, int y, int p) {
        if (p == word.size()) 
            return true;
        
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (isValid(a, b) && !visited[a][b] && map[a][b] == word[p]) {
                visited[a][b] = true;
                flag = DFS(a, b, p + 1);
                visited[a][b] = false;
                if (flag) return true;
            }
        }
        return false;
    }

private:
    static const int MAXN = 1010;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int row, col;
    // 56ms judge large
    // much faster than pass-by-reference
    char map[MAXN][MAXN];
    bool visited[MAXN][MAXN];
    string word;
};
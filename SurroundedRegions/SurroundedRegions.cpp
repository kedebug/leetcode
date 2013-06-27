
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

class Solution {
public:
	void solve(vector<vector<char>> &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		
		if (board.empty()) return;
		
		row = board.size();
		col = board[0].size();

		for (int i = 0; i < row; i++) {
			if (board[i][0] == 'O') dfs(i, 0, board);
			if (board[i][col-1] == 'O') dfs(i, col-1, board);
		}
		for (int j = 1; j < col; j++) {
			if (board[0][j] == 'O') dfs(0, j, board);
			if (board[row-1][j] == 'O') dfs(row-1, j, board);
		}
		for (int i = 0; i < row; i++)  {
			for (int j = 0; j < col; j++) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == 'B') board[i][j] = 'O';
			}
		}
	}

	void dfs(int x, int y, vector<vector<char>> &board) {
		board[x][y] = 'B';

		for (int k = 0; k < 4; k++) {
			int i = x + dx[k];
			int j = y + dy[k];
			if (check(i, j) && board[i][j] == 'O') {
				dfs(i, j, board);
			}
		}
	}

	bool check(int x, int y) {
		if (x >= 0 && x < row && y >= 0 && y < col) {
			return true;
		}
		return false;
	}
private:
	int row, col;
};

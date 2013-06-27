const int MAXN = 2010;
const int INFS = 0x3fffffff;

class Solution {
public:
	int minCut(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		
		int n = s.size();
		memset(dp, false, sizeof(dp));
		for (int i = 0; i < n; i++)
			dp[i+1][i] = dp[i][i] = true;
		for (int d = 1; d < n; d++)
			for (int i = 0, j = i+d; j < n; i++, j++)
				if (s[i] == s[j]) 
					dp[i][j] |= dp[i+1][j-1];
		for (int i = 0; i < n; i++)
			F[i] = INFS;
		F[0] = 0;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < i; j++)
				if (dp[0][i])
					F[i] = 0;
				else if (dp[j+1][i])
					F[i] = min(F[i], F[j] + 1);
		return F[n-1];

	}
private:
	bool dp[MAXN][MAXN];
	int F[MAXN];
};

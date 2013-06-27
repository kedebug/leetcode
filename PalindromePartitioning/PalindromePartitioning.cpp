class Solution {
public:
    vector<vector<string> > partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ans.clear();
        dynamic(s);
        vector<string> v;
        dfs(s, 0, v);
        return ans;

    }
    void dfs(string& s, int p, vector<string>& v) {
        if (p == s.size()) {
            ans.push_back(v);
            return ;
        }
        string temp;
        bool flag = false;
        for (int i = p; i < s.size(); i++) {
            temp += s[i];
            if (dp[p][i]) {
                v.push_back(temp);
                dfs(s, i+1, v);
                v.pop_back();
            }
        }        
    }

    void dynamic(string& s) {
        memset(dp, false, sizeof(dp));
        int len = s.size();
        for (int i = 0; i < len; i++) 
            dp[i][i] = true, dp[i+1][i] = true;
        for (int d = 1; d < len; d++) {
            for (int i = 0, j = i+d; j < len; i++, j++) {
                if (s[i] == s[j]) 
                    dp[i][j] |= dp[i+1][j-1];
            }
        }
    }
private:
    vector<vector<string> > ans;
    bool dp[1000][1000];
};

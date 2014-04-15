class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<int> sk;
        dfs(result, sk, s, 0, 0);
        return result;
    }
    
    void dfs(vector<string>& result, vector<int>& sk, const string& s, int val, int pos) {
        if (sk.size() > 4) {
            return;
        }
        
        if (pos == s.size()) {
            if (sk.size() < 4 || val != 0) {
                return;
            }
            string ip;
            ip += to_string(sk[0]);
            for (int i = 1; i < 4; i++) {
                ip += ".";
                ip += to_string(sk[i]);
            }
            result.push_back(ip);
            return;
        }
        
        val = val * 10 + s[pos] - '0';
        if (val > 255) {
            return;
        }
        if (val != 0) {
            dfs(result, sk, s, val, pos + 1);
        }
        sk.push_back(val);
        dfs(result, sk, s, 0, pos + 1);
        sk.pop_back();
    }
};

class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int needFind[256] = {0};
        int hasFound[256] = {0};
        int count = 0, minLen = INT_MAX;
        string result = "";
        
        for (int i = 0; i < T.size(); i++)
            needFind[T[i]] += 1;
        
        for (int low = 0, high = 0; high < S.size(); high++) {
            if (needFind[S[high]] == 0) 
                continue;
            
            hasFound[S[high]] += 1;
            if (hasFound[S[high]] <= needFind[S[high]])
                count += 1;
            
            if (count == T.size()) {
                while (low < high) {
                    if (needFind[S[low]] == 0) {
                        low += 1;
                        continue;
                    }
                    if (hasFound[S[low]] > needFind[S[low]])
                        hasFound[S[low]] -= 1;
                    else
                        break;
                    low += 1;
                }
                if (minLen > high - low + 1) {
                    minLen = high - low + 1;
                    result = S.substr(low, minLen);
                }
            }
        }
        return result;
    }
};
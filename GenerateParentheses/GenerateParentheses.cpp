class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> result;
        if (n == 0) return result;
        
        string parenthesis;
        DFS(parenthesis, 0, 0, n, result);
        
        return move(result);
    }
    
    void DFS(string& parenthesis, int left, int right, int n, vector<string>& result) {
        if (right > left) return;
        
        if (left == right && left == n) {
            result.push_back(parenthesis);
            return;
        }
        
        if (left == right && left < n) {
            parenthesis += '(';
            DFS(parenthesis, left + 1, right, n, result);
            parenthesis.erase(parenthesis.size() - 1, 1);
            return;
        }
        if (left > right && left < n) {
            parenthesis += '(';
            DFS(parenthesis, left + 1, right, n, result);
            parenthesis.erase(parenthesis.size() - 1, 1);
            
            parenthesis += ')';
            DFS(parenthesis, left, right + 1, n, result);
            parenthesis.erase(parenthesis.size() - 1, 1);
        }
        if (left == n && right < n) {
            parenthesis += ')';
            DFS(parenthesis, left, right + 1, n, result);
            parenthesis.erase(parenthesis.size() - 1, 1);
        }
        
    }
};


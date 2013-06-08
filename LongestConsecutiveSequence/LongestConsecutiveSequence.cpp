class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<int> Q;
        for (int i = 0; i < num.size(); i++) {
            Q.push(num[i]);
        }
        int ret = 1;
        int maxlen = 1;
        int temp = Q.top();
        Q.pop();
        while (!Q.empty()) {
            if (temp - 1 == Q.top()) {
                temp -= 1;
                maxlen += 1; 
            } else if (temp != Q.top()) {
                temp = Q.top();
                maxlen = 1;
            }
            Q.pop();
            ret = max(maxlen, ret);
        }
        return ret;
    }
};
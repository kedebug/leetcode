class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        stack<char> ops;
        
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
                int value = atoi(tokens[i].c_str());
                nums.push(value);
            } else if (tokens[i].size() >= 2) {
                int value = atoi(tokens[i].c_str());
                nums.push(value);
            } else {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                int c;
                switch (tokens[i][0]) {
                    case '+':
                        c = a + b;
                        break;
                    case '-':
                        c = a - b;
                        break;
                    case '*':
                        c = a * b;
                        break;
                    case '/':
                        c = a / b;
                        break;
                }
                nums.push(c);
            }
        }
        return nums.top();
    }
};

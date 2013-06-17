/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int>> result;
        if (root == NULL) return result;
        
        stack<TreeNode*> stackNow;
        stack<TreeNode*> stackNext;
        vector<int> value;
        bool left2right = true;
        stackNow.push(root);
        
        while (!stackNow.empty()) {
            TreeNode *node = stackNow.top();
            stackNow.pop();
            value.push_back(node->val);
            if (left2right) {
                if (node->left)
                    stackNext.push(node->left);
                if (node->right)
                    stackNext.push(node->right);
            }
            else {
                if (node->right)
                    stackNext.push(node->right);
                if (node->left)
                    stackNext.push(node->left);
            }
            if (stackNow.empty()) {
                result.push_back(value);
                value.clear();
                left2right = !left2right;
                swap(stackNow, stackNext);
            }
        }
        return move(result);
    }
};
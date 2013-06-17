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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int>> result;
        if (root == NULL) return result;
        
        queue<TreeNode*> nodeQueue;
        vector<int> value;
        nodeQueue.push(root);
        int nodeNow = 1;
        int nodeNext = 0;
        
        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            nodeNow -= 1;
            value.push_back(node->val);
            if (node->left) {
                nodeQueue.push(node->left);
                nodeNext += 1;
            }
            if (node->right) {
                nodeQueue.push(node->right);
                nodeNext += 1;
            }
            if (nodeNow == 0) {
                result.push_back(value);
                value.clear();
                nodeNow = nodeNext;
                nodeNext = 0;
            }
        }
        return move(result);
    }
};
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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root == NULL) return;
        
        stack<TreeNode*> tree_stack;
        TreeNode *flatten_node = NULL;
        tree_stack.push(root);
        
        while (!tree_stack.empty()) {
            TreeNode *node = tree_stack.top();
            tree_stack.pop();
            if (node->right) {
                tree_stack.push(node->right);
                node->right = NULL;
            }
            if (node->left) {
                tree_stack.push(node->left);
                node->left = NULL;
            }
            if (flatten_node == NULL)
                flatten_node = node;
            else {
                flatten_node->right = node;
                flatten_node = flatten_node->right;
            }
        }
    }
};
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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return false;
        return dfs(root, 0, sum);
        
    }
    
    bool dfs(TreeNode *node, int value, int target) {
        if (node->left == NULL && node->right == NULL) {
            if (value + node->val == target) 
                return true;
            else
                return false;
        } 
        bool flag = false;
        if (node->left)
            flag = dfs(node->left, node->val + value, target);
        if (flag) return true;
        if (node->right)
            return dfs(node->right, node->val + value, target);
    }
};
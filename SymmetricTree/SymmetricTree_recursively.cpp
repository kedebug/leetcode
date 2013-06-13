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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return true;
        return dfs(root->left, root->right);
        
    }
    bool dfs(TreeNode *lhs, TreeNode *rhs) {
        if (lhs == NULL && rhs == NULL)
            return true;
        if (lhs == NULL || rhs == NULL)
            return false;
            
        if (lhs->val == rhs->val) {
            bool flag = dfs(lhs->left, rhs->right);
            if (!flag) return false;
            return dfs(lhs->right, rhs->left);
        }
        return false;
    }
};
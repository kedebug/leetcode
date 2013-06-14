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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        int lf = INT_MAX, rt = INT_MAX;
        if (root->left)
            lf = 1 + minDepth(root->left);
        if (root->right)
            rt = 1 + minDepth(root->right);
        return min(lf, rt);
    }
};
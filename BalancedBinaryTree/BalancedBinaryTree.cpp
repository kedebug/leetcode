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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool flag = true;
        dfs(root, flag);
        return flag;
    }
    int dfs(TreeNode* node, bool& flag) {
        if (node == NULL)
            return 0;
        int lf = 1 + dfs(node->left, flag);
        int rt = 1 + dfs(node->right, flag);
        
        if (abs(rt - lf) > 1)
            flag = false;
        return max(lf, rt);
    }
};
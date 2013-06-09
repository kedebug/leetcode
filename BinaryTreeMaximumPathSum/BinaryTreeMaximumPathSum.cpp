/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int INFS = 0x3fffffff;
 
struct NodeInfo {
    int maxval, maxfromroot;
    NodeInfo() : maxval(-INFS), maxfromroot(-INFS) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        NodeInfo res = dfs(root);
        return res.maxval;
        
    }
    NodeInfo dfs(TreeNode *node) {
        NodeInfo left, root, right;
        if (node == NULL) {
            return root;
        }
        if (node->left)
            left = dfs(node->left);
        if (node->right)
            right = dfs(node->right);
        
        int l = max(0, left.maxfromroot);
        int r = max(0, right.maxfromroot);
        
        root.maxfromroot = node->val + max(0, max(l, r));
        root.maxval = max(left.maxval, right.maxval);
        root.maxval = max(root.maxval, l + r + node->val);
        return root;
    }
private:

};
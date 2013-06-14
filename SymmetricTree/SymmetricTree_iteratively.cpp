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
        queue<TreeNode*> lhs, rhs;
        lhs.push(root->left);
        rhs.push(root->right);
        while (!lhs.empty() && !rhs.empty()) {
            TreeNode *l = lhs.front(); lhs.pop();
            TreeNode *r = rhs.front(); rhs.pop();
            if (l == NULL && r == NULL) continue;
            if (l == NULL || r == NULL) return false;
            if (l->val != r->val) return false;
            lhs.push(l->left); lhs.push(l->right);
            rhs.push(r->right); rhs.push(r->left);
        }
        if (lhs.empty() && rhs.empty())
            return true;
        else
            return false;
    }
};
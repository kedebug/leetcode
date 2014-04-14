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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* dfs(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        if (l1 > r1) {
            return NULL;
        }
        if (l1 == r1) {
            return new TreeNode(preorder[l1]);
        }
        TreeNode* root = new TreeNode(preorder[l1]);
        for (int i = l2; i <= r2; i++) {
            if (inorder[i] == preorder[l1]) {
                root->left = dfs(preorder, l1 + 1, l1 + i - l2, inorder, l2, i - 1);
                root->right = dfs(preorder, l1 + i - l2 + 1, r1, inorder, i + 1, r2);
                return root;
            }
        }
        return NULL;
    }
};

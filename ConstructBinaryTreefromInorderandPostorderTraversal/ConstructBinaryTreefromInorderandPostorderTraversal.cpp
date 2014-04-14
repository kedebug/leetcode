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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) {
            return NULL;
        }
        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* dfs(vector<int>& inorder, int l1, int r1, vector<int>& postorder, int l2, int r2) {
        if (l1 > r1) {
            return NULL;
        }
        if (l1 == r1) {
            return new TreeNode(inorder[l1]);
        }
        TreeNode* root = new TreeNode(postorder[r2]);
        for (int i = l1; i <= r1; i++) {
            if (inorder[i] == postorder[r2]) {
                root->left = dfs(inorder, l1, i - 1, postorder, l2, l2 + i - l1 - 1);
                root->right = dfs(inorder, i + 1, r1, postorder, l2 + i - l1, r2 - 1);
                return root;
            }
        }
        return NULL;
    }
};

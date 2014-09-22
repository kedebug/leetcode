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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode* node = root;
        while (node) {
            if (node->left == NULL) {
                result.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* next = node->left;
                while (next->right && next->right != node) {
                    next = next->right;
                }
                if (next->right == NULL) {
                    next->right = node;
                    result.push_back(node->val);
                    node = node->left;
                } else {
                    next->right = NULL;
                    node = node->right;
                }
            }
        }
        return result;
    }
};

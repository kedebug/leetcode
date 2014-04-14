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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return dfs(num, 0, num.size() - 1);
    }
    TreeNode* dfs(vector<int>& num, int start, int limit) {
        if (start > limit) {
            return NULL;
        }
        if (start == limit) {
            return new TreeNode(num[start]);
        }
        int middle = (start + limit) / 2;
        TreeNode* root = new TreeNode(num[middle]);
        root->left = dfs(num, start, middle - 1);
        root->right = dfs(num, middle + 1, limit);
        return root;
    }
};

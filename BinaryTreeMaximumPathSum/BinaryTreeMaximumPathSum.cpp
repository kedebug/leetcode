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
    int maxPathSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int maxsum = INT_MIN;
        dfs(root, &maxsum);
        return maxsum;
    }
    
    int dfs(TreeNode* node, int* maxsum) {
        if (node == NULL) {
            return 0;
        }
        int left = dfs(node->left, maxsum);
        int right = dfs(node->right, maxsum);
        int val = node->val;
        if (max(left, right) > 0) {
            val += max(left, right);
        }
        int sum = node->val;
        if (left > 0) {
            sum += left;
        }
        if (right > 0) {
            sum += right;
        }
        *maxsum = max(*maxsum, sum);
        return val;
    }
};

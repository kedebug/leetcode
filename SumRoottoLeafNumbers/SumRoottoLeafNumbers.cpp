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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
        
    }
    void dfs(TreeNode *node, int val, int& sum) {
        if (node == NULL) return;
        
        val *= 10;
        val += node->val;
        
        if (node->left == NULL && node->right == NULL) {
            sum += val;
            return;
        }
    
        if (node->left) {
            dfs(node->left, val, sum);
        }
        if (node->right) {
            dfs(node->right, val, sum);
        }
    }
};

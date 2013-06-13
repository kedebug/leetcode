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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, 0, sum, path, result);
        return move(result);
        
    }
    void dfs(TreeNode *node, int value, int sum, 
        vector<int>& path, vector<vector<int>>& result) {
        if (node == NULL) return;
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            if (node->val + value == sum) {
                result.push_back(path);   
            }
            path.pop_back();
            return;
        }
        if (node->left) 
            dfs(node->left, node->val + value, sum, path, result);
        if (node->right)
            dfs(node->right, node->val + value, sum, path, result);
        path.pop_back();
    }
};
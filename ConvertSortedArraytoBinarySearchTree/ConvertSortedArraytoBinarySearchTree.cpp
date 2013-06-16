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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.empty()) return NULL;
        TreeNode *root = new TreeNode(0);
        dfs(root, 0, num.size() - 1, num);
        return root;
        
    }
    void dfs(TreeNode *root, int left, int right, vector<int>& num) {
        if (left == right) {
            root->val = num[left];
            root->left = root->right = NULL;
            return;
        }
        int mid = (left + right) / 2;
        root->val = num[mid];
        root->right = new TreeNode(0);
        dfs(root->right, mid + 1, right, num);
        if (mid != left) {
            root->left = new TreeNode(0);
            dfs(root->left, left, mid - 1, num);
        }
    }
};
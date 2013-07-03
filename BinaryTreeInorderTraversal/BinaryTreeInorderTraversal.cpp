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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> inorder;
        stack<TreeNode*> tree_stack;
        TreeNode *node = root;
        
        while (node || !tree_stack.empty()) {
            while (node) {
                tree_stack.push(node);
                node = node->left;
            }
            if (!tree_stack.empty()) {
                node = tree_stack.top();
                tree_stack.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};

// solution 2, O(1) space
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> inorder;
        TreeNode *current = root;
        
        while (current != NULL) {
            if (current->left == NULL) {
                inorder.push_back(current->val);
                current = current->right;
            }
            else {
                TreeNode *prev = current->left;
                while (prev->right && prev->right != current)
                    prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = current;
                    current = current->left;
                }
                else {
                    inorder.push_back(current->val);
                    prev->right = NULL;
                    current = current->right;
                }
            }
        }
        return inorder;
    }
};
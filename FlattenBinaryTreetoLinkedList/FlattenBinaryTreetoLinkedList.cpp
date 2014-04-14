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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root == NULL) return;
        
        stack<TreeNode*> tree_stack;
        TreeNode *flatten_node = NULL;
        tree_stack.push(root);
        
        while (!tree_stack.empty()) {
            TreeNode *node = tree_stack.top();
            tree_stack.pop();
            if (node->right) {
                tree_stack.push(node->right);
                node->right = NULL;
            }
            if (node->left) {
                tree_stack.push(node->left);
                node->left = NULL;
            }
            if (flatten_node == NULL) {
                flatten_node = node;
            } else {
                flatten_node->right = node;
                flatten_node = flatten_node->right;
            }
        }
    }
};

// recursion
class Solution {
public:
    void flatten(TreeNode *root) {
        dfs(root);
    }
    
    pair<TreeNode*, TreeNode*> dfs(TreeNode* root) {
        if (root == NULL) {
            return make_pair((TreeNode*)NULL, (TreeNode*)NULL);
        }
        pair<TreeNode*, TreeNode*> left = dfs(root->left);
        pair<TreeNode*, TreeNode*> right = dfs(root->right);
        root->left = NULL;
        root->right = NULL;
        if (left.first && right.first) {
            root->right = left.first;
            left.second->right = right.first;
            return make_pair(root, right.second);
        } else if (left.first) {
            root->right = left.first;
            return make_pair(root, left.second);
        } else if (right.first) {
            root->right = right.first;
            return make_pair(root, right.second);
        }
        return make_pair(root, root);
    }
};

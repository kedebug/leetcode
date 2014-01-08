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
    bool isValidBST(TreeNode *root) {
        if (root == NULL)
            return true;
        
        return valid(root->left, INT_MIN, root->val) && 
               valid(root->right, root->val, INT_MAX);
    }
    
    bool valid(TreeNode *node, int start, int limit) {
        if (node == NULL)
            return true;
        
        if (node->val >= limit || node->val <= start)
            return false;
            
        return valid(node->left, start, node->val) &&
               valid(node->right, node->val, limit);
    }
};

//
// Solution 2, O(1) space
//
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeNode *parent = NULL;
        TreeNode *current = root;
        bool flag = true;
        
        while (current != NULL) {
            if (current->left == NULL) {
                if (parent && parent->val >= current->val)
                    flag = false; 
                
                parent = current;
                current = current->right;
            }
            else {
                TreeNode *left_right_most = current->left;
                while (left_right_most->right && left_right_most->right != current)
                    left_right_most = left_right_most->right;
                
                if (left_right_most->right == NULL) {
                    left_right_most->right = current;
                    current = current->left;
                }
                else {
                    if (parent && parent->val >= current->val)
                        flag = false;
                    
                    left_right_most->right = NULL;
                    parent = current;
                    current = current->right;
                }
            }
        }
        return flag;
    }
};
// http://fisherlei.blogspot.com/2012/12/leetcode-recover-binary-search-tree.html

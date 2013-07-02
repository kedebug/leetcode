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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root == NULL) return true;
        TreeNode *parent = NULL;
        return isValidBST(root, parent);
    }
    
    bool isValidBST(TreeNode *current, TreeNode *&parent) {
        if (current == NULL) return true;     
        bool valid = true;
        valid = isValidBST(current->left, parent);
        if (parent && parent->val >= current->val)
            return false;
        parent = current;
        valid &= isValidBST(current->right, parent);
        return valid;
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
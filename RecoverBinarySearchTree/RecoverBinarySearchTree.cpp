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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeNode *parent = NULL;
        TreeNode *current = root;
        TreeNode *mistake_node1 = NULL;
        TreeNode *mistake_node2 = NULL;
        
        while (current != NULL) {
            if (current->left == NULL) {
                if (parent && parent->val > current->val) {
                    if (mistake_node1 == NULL) 
                        mistake_node1 = parent;
                    mistake_node2 = current;
                }
                parent = current;
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
                    if (parent->val > current->val) {
                        if (mistake_node1 == NULL) 
                            mistake_node1 = parent;
                        mistake_node2 = current;
                    }
                    prev->right = NULL;
                    parent = current;
                    current = current->right;
                }
            }
        }
        if (mistake_node1 && mistake_node2)
            swap(mistake_node1->val, mistake_node2->val);
    }
};
// http://fisherlei.blogspot.com/2012/12/leetcode-recover-binary-search-tree.html
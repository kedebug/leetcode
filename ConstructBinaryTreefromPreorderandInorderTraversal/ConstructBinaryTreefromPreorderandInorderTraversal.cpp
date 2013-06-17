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
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (preorder.empty()) return NULL;
        
        TreeNode *root = new TreeNode(0);
        build(root, preorder.size(), preorder, 0, inorder, 0);
        return root;
    }
    
    void build(TreeNode *root, int size, vector<int>& preorder, int preLeft, vector<int>& inorder, int inLeft) {
        if (size == 1) {
            root->val = preorder[preLeft];
            return ;
        }
        int sizeLeft = 0;
        for (int i = 0; i < size; i++) {
            if (preorder[preLeft] == inorder[i+inLeft])
                break;
            sizeLeft += 1;
        }
        root->val = preorder[preLeft];
        if (sizeLeft > 0) {
            root->left = new TreeNode(0);
            build(root->left, sizeLeft, preorder, preLeft + 1, inorder, inLeft);
        }
        int sizeRight = size - sizeLeft - 1;
        if (sizeRight > 0) {
            root->right = new TreeNode(0);
            build(root->right, sizeRight, preorder, preLeft + sizeLeft + 1, inorder, inLeft + sizeLeft + 1);
        }
    }
};
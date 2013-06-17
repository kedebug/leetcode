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
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int size = inorder.size();
        if (size == 0) return NULL;
        
        TreeNode *root = new TreeNode(0);
        build(root, size, inorder, 0, postorder, 0);
        return root;
    }
    
    void build(TreeNode *root, int size, vector<int>& inorder, int inLeft, vector<int>& postorder, int postLeft) {
        assert(size > 0);
        
        int pivot = postorder[postLeft+size-1];
        root->val = pivot;
        
        if (size == 1) return;
        
        int sizeleft = 0;
        for (int i = 0; i < size; i++) {
            if (inorder[inLeft+i] == pivot)
                break;
            sizeleft += 1;
        }
        
        if (sizeleft > 0) {
            root->left = new TreeNode(0);
            build(root->left, sizeleft, inorder, inLeft, postorder, postLeft);
        }
        int sizeright = size - sizeleft - 1;
        if (sizeright > 0) {
            root->right = new TreeNode(0);
            build(root->right, sizeright, inorder, inLeft + sizeleft + 1, postorder, postLeft + sizeleft);
        }
    }
};
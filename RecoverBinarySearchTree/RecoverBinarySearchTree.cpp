// O(n) time, O(1) space
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode* node = root;
        TreeNode* prev = NULL;
        TreeNode* prev1 = NULL;
        TreeNode* curr1 = NULL;
        TreeNode* prev2 = NULL;
        TreeNode* curr2 = NULL;
        
        while (node != NULL) {
            if (node->left == NULL) {
                prev = node;
                node = node->right;
            } else {
                TreeNode* next = node->left;
                while (next->right && next->right != node) {
                    next = next->right;
                }
                if (next->right == NULL) {
                    next->right = node;
                    node = node->left;
                } else {
                    prev = node;
                    node = node->right;
                    next->right = NULL;
                }
            }
            if (prev && node && prev->val > node->val) {
                if (prev1 == NULL) {
                    prev1 = prev, curr1 = node;
                } else {
                    prev2 = prev, curr2 = node;
                }
            }
        }
        if (prev1 && curr2) {
            swap(prev1->val, curr2->val);
        } else {
            swap(prev1->val, curr1->val);
        }
    }
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        TreeLinkNode* leftmost = root;
        while (leftmost) {
            TreeLinkNode* node = leftmost;
            TreeLinkNode* prev = NULL;
            leftmost = NULL;
            while (node) {
                if (node->left) {
                    if (leftmost == NULL) {
                        leftmost = node->left;
                    }
                    if (prev == NULL) {
                        prev = node->left;
                    } else {
                        prev->next = node->left;
                        prev = node->left;
                    }
                }
                if (node->right) {
                    if (leftmost == NULL) {
                        leftmost = node->right;
                    }
                    if (prev == NULL) {
                        prev = node->right;
                    } else {
                        prev->next = node->right;
                        prev = node->right;
                    }
                }
                node = node->next;
            }
        }
    }
};

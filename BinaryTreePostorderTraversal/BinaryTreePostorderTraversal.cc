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
    void print(vector<int>& result, TreeNode* from, TreeNode* to) {
        vector<int> temp;
        while (true) {
            temp.push_back(from->val);
            if (from == to) {
                break;
            }
            from = from->right;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
    }
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode prev(0);
        prev.left = root;
        TreeNode* curr = &prev;
        while (curr != NULL) {
            if (curr->left == NULL) {
                curr = curr->right;
            } else {
                TreeNode* next = curr->left;
                while (next->right && next->right != curr) {
                    next = next->right;
                }
                if (next->right == NULL) {
                    next->right = curr;
                    curr = curr->left;
                } else {
                    print(result, curr->left, next);
                    next->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};

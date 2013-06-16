/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
        TreeNode *root = new TreeNode(0);
        dfs(root, head);
        return root;
        
    }
    void dfs(TreeNode *root, ListNode *node) {
        if (node->next == NULL) {
            root->val = node->val;
            root->left = root->right = NULL;
            return;
        }
        ListNode *prev = node;
        ListNode *slow = node->next;
        ListNode *fast = node->next->next;
        while (fast != NULL && fast->next != NULL) {
            prev = prev->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        root->val = slow->val;
        root->left = new TreeNode(0);
        prev->next = NULL;
        dfs(root->left, node);
        
        if (slow->next != NULL) {
            root->right = new TreeNode(0);
            dfs(root->right, slow->next);
        }
    }
};













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
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return new TreeNode(head->val);
        }
        ListNode prevhead(0);
        prevhead.next = head;
        ListNode* prev = &prevhead;
        ListNode* one = head;
        ListNode* two = head;
        while (two && two->next) {
            prev = prev->next;
            one = one->next;
            two = two->next->next;
        }
        TreeNode* root = new TreeNode(one->val);
        ListNode* temp = one->next;
        prev->next = NULL;
        one->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(temp);
        return root;
    }
};










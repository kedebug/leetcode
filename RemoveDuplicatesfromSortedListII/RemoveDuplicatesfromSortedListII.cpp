/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode prevhead(0);
        ListNode* prev = &prevhead;
        ListNode* curr = head;
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                ListNode* next = curr->next;
                while (next && next->val == curr->val) {
                    next = next->next;
                }
                curr = next;
            } else {
                prev->next = curr;
                prev = prev->next;
                curr = curr->next;
            }
        }
        prev->next = NULL;
        return prevhead.next;
    }
};

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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode new_head(0);
        new_head.next = head;
        
        ListNode* one = &new_head;
        ListNode* two = &new_head;
        
        while (two && two->next) {
            one = one->next;
            two = two->next->next;
        }
        
        ListNode* node = one->next;
        one->next = NULL;
        ListNode* left = sortList(new_head.next);
        ListNode* right = sortList(node);
        
        
        ListNode* sorted_head = NULL;
        ListNode* sorted_curr = NULL;
        
        if (left->val < right->val) {
            sorted_head = sorted_curr = left;
            left = left->next;
        } else {
            sorted_head = sorted_curr = right;
            right = right->next;
        }
        
        while (left && right) {
            if (left->val < right->val) {
                sorted_curr->next = left;
                sorted_curr = left;
                left = left->next;
            } else {
                sorted_curr->next = right;
                sorted_curr = right;
                right = right->next;
            }
        }
        
        while (left) {
            sorted_curr->next = left;
            sorted_curr = left;
            left = left->next;
        }
        while (right) {
            sorted_curr->next = right;
            sorted_curr = right;
            right = right->next;
        }
        
        sorted_curr->next = NULL;
        return sorted_head;
    }
};

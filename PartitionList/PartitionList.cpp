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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode less_than_head(0);
        ListNode no_less_than_head(0);
        ListNode *less_than = &less_than_head;
        ListNode *no_less_than = &no_less_than_head;
        
        ListNode *node = head;
        while (node != NULL) {
            if (node->val < x) {
                less_than->next = node;
                node = node->next;
                less_than = less_than->next;
            }
            else {
                no_less_than->next = node;
                node = node->next;
                no_less_than = no_less_than->next;
            }
        }
        no_less_than->next = NULL;
        less_than->next = no_less_than_head.next;
        return less_than_head.next;
    }
};
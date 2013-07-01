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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode prev_head(0);
        ListNode *sorted_list = &prev_head;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                sorted_list->next = l1;
                l1 = l1->next;
                sorted_list = sorted_list->next;
            }
            else {
                sorted_list->next = l2;
                l2 = l2->next;
                sorted_list = sorted_list->next;
            }
        }
        
        while (l1) {
            sorted_list->next = l1;
            l1 = l1->next;
            sorted_list = sorted_list->next;
        }
        while (l2) {
            sorted_list->next = l2;
            l2 = l2->next;
            sorted_list = sorted_list->next;
        }
        return prev_head.next;
    }
};
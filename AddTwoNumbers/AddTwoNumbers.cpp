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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int carry = 0;
        ListNode *list = new ListNode(0);
        ListNode *head = list;
        ListNode *prev = list;
        while (l1 && l2) {
            carry += l1->val + l2->val;
            
            list = new ListNode(0);
            list->val = carry % 10;
            carry /= 10;

            l1 = l1->next;
            l2 = l2->next;
            prev->next = list;
            prev = prev->next;
        }
        while (l1) {
            carry += l1->val;
            
            list = new ListNode(0);
            list->val = carry % 10;
            carry /= 10;

            l1 = l1->next;
            prev->next = list;
            prev = prev->next;
        }
        while (l2) {
            carry += l2->val;
            
            list = new ListNode(0);
            list->val = carry % 10;
            carry /= 10;

            l2 = l2->next;
            prev->next = list;
            prev = prev->next;
        }
        if (carry) {
            list = new ListNode(0);
            list->val = carry;
            prev->next = list;
            prev = prev->next;
        }
        return head->next;
    }
};

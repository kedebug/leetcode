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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (head == NULL) return NULL;
        
        ListNode prevHead(0);
        prevHead.next = head;
        ListNode *prev = &prevHead;
        ListNode *left = head;
        ListNode *right = head->next;
        
        while (left && right) {
            prev->next = right;
            left->next = right->next;
            right->next = left;
            
            prev = left;
            left = left->next;
            if (left) right = left->next;
            else right = NULL;
        }
        return prevHead.next;
    }
};
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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (head == NULL)
            return NULL;
        
        ListNode *prev = head;
        ListNode *node = head->next;
        
        while (node != NULL) {
            if (node->val == prev->val) {
                ListNode *dele = node;
                prev->next = NULL;
                node = node->next;
                delete dele;
            }
            else {
                prev->next = node;
                prev = prev->next;
                node = node->next;
            }
        }
        return head;
    }
};
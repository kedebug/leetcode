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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (head == NULL) return head;
        
        ListNode *node = head;
        int len = 0;
        while (node) {
            len += 1;
            node = node->next;
        }
        if (k >= len) 
            k %= len;
            
        if (k == 0) 
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        
        for (int i = 0; i < len - 1; i++)
            fast = fast->next;
        for (int i = 0; i < len - k - 1; i++)
            slow = slow->next;
        
        if (slow == fast)
            return head;
        
        ListNode *newHead = slow->next;
        slow->next = NULL;
        fast->next = head;
        return newHead;
        
    }
};
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode prevHead(0);
        prevHead.next = head;
        
        ListNode *prev = &prevHead;
        ListNode *slow = head;
        ListNode *fast = head;
        
        for (int i = 0; i < n; i++)
            fast = fast->next;
            
        while (fast != NULL) {
            prev = prev->next;
            slow = slow->next;
            fast = fast->next;
        }
        
        prev->next = slow->next;
        delete slow;
        return prevHead.next;
    }
};
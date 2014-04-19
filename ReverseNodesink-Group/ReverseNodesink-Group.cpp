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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode* node = head;
        int len = 0;
        while (node) {
            len++;
            node = node->next;
        }
        if (k > len) {
            return head;
        }
        
        ListNode prevhead(0);
        prevhead.next = head;
        
        ListNode* curr = head;
        ListNode* prev = &prevhead;
        
        while (curr) {
            int count = k - 1;
            ListNode* last = curr;
            while (count && last) {
                count--;
                last = last->next;
            }
            if (count == 0 && last) {
                ListNode* next = last->next;
                last->next = NULL;
                ListNode* l = reverse(curr);
                curr->next = next;
                prev->next = l;
                prev = curr;
                curr = next;
            } else {
                break;
            }
        }
        return prevhead.next;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode prevhead(0);
        while (head) {
            ListNode* next = head->next;
            head->next = prevhead.next;
            prevhead.next = head;
            head = next;
        }
        return prevhead.next;
    }
};

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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //
        // only travel the list for one time
        //
        
        ListNode node(0);
        node.next = head;
        ListNode *slow = head;
        ListNode *fast = &node;
        
        for (int i = 0; i < k; i++) {
            if (fast && fast->next) fast = fast->next;
            else return head;
        }
        
        bool kRemaind = true;
        bool getHead = false;
        ListNode *newHead = NULL;
        
        while (kRemaind) {          
            ListNode *tail = slow;
            ListNode *prev = NULL;
            ListNode *next = NULL;
            
            for (int i = 0; i < k; i++) {
                next = slow->next;
                slow->next = prev;
                prev = slow;
                slow = next;
                
                if (fast && fast->next) 
                    fast = fast->next;
                else 
                    kRemaind = false;
            }
            if (kRemaind)
                tail->next = fast;
            else 
                tail->next = slow;
            
            if (!getHead) {
                newHead = prev;
                getHead = true;
            }
        }
        return newHead;
    }
};
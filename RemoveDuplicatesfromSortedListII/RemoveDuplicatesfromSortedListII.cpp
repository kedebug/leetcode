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
            return head;
        
        ListNode preHead(0);
        preHead.next = head;
        
        ListNode *preprev = &preHead;
        ListNode *prev = head;
        ListNode *node = head->next;
        bool flag = false;
        
        while (node != NULL) {
            if (prev->val == node->val) {
                ListNode *del = node;
                node = node->next;
                flag = true;
                delete del;
            }
            else {
                if (flag) {
                    flag = false;
                    preprev->next = node;
                    prev = node;
                    node = node->next;
                } 
                else {
                    preprev = prev;
                    prev = node;
                    node = node->next;
                }
            }
        }
        if (flag) {
            preprev->next = NULL;
            delete prev;
        }
        
        return preHead.next;
    }
};

// Accepted after my first commit, yeah.
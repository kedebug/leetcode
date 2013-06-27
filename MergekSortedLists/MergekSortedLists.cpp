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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = lists.size();
        ListNode head(0);
        ListNode *node = &head;
        
        //
        // Time complexity O(n*K)
        // n stands for the max length of the list in lists
        //
        while (true) {
            int minValue = INT_MAX;
            int pos = -1;
            for (int i = 0; i < n; i++) {  
                if (lists[i] != NULL && minValue > lists[i]->val) {
                    pos = i;
                    minValue = lists[i]->val;
                }  
            }
            if (pos == -1) break;
            node->next = lists[pos];
            node = node->next;
            lists[pos] = lists[pos]->next;
        }
        return head.next;
    }
};
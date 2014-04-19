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
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left > right) {
            return NULL;
        }
        if (left == right) {
            return lists[left];
        }
        int mid = (left + right) / 2;
        ListNode* l1 = merge(lists, left, mid);
        ListNode* l2 = merge(lists, mid + 1, right);
        
        ListNode head(0);
        ListNode* curr = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        while (l1) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        while (l2) {
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        return head.next;
    }
};

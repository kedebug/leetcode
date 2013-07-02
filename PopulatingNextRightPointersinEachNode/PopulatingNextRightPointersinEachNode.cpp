/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeLinkNode *link_head = root;
        TreeLinkNode *next_link_head = NULL;
        
        while (link_head) {
            if (link_head->left == NULL) 
                break;
            next_link_head = link_head->left;
            next_link_head->next = link_head->right;
            TreeLinkNode *link_node = link_head;
            TreeLinkNode *next_link_node = link_head->right;
            while (link_node->next) {
                next_link_node->next = link_node->next->left;
                next_link_node->next->next = link_node->next->right;
                next_link_node = link_node->next->right;
                link_node = link_node->next;
            }
            link_head = next_link_head;
        }
    }
};
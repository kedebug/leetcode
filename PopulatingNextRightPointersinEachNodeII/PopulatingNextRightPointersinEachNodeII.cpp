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
        
        while (link_head) {
            TreeLinkNode *next_link_head = NULL;
            TreeLinkNode *next_link_node = NULL;
            
            while (link_head) {
                if (link_head->left) {
                    next_link_head = link_head->left;
                    next_link_node = next_link_head;
                }
                if (link_head->right) {
                    if (next_link_node) {
                        next_link_node->next = link_head->right;
                        next_link_node = next_link_node->next;
                    }
                    else {
                        next_link_head = link_head->right;
                        next_link_node = next_link_head;
                    }
                }
                if (next_link_head) break;
                link_head = link_head->next;
            }
            if (next_link_head == NULL) break;
            
            while (link_head->next) {
                if (link_head->next->left) {
                    next_link_node->next = link_head->next->left;
                    next_link_node = next_link_node->next;
                }
                if (link_head->next->right) {
                    next_link_node->next = link_head->next->right;
                    next_link_node = next_link_node->next;
                }
                link_head = link_head->next;
            }
            link_head = next_link_head;
        }
    }
};


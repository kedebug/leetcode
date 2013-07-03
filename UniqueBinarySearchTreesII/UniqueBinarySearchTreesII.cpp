/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return generateTreesHelper(1, n);
    }
    
    vector<TreeNode *> generateTreesHelper(int left, int right) {
        vector<TreeNode *> trees;
        if (left > right) {
            trees.push_back(NULL);
            return trees;
        }
        for (int r = left; r <= right; r++) {
            vector<TreeNode *> left_trees = generateTreesHelper(left, r - 1);
            vector<TreeNode *> right_trees = generateTreesHelper(r + 1, right);
            for (int i = 0; i < left_trees.size(); i++) {
                for (int j = 0; j < right_trees.size(); j++) {
                    TreeNode *root = new TreeNode(r);
                    root->left = left_trees[i];
                    root->right = right_trees[j];
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};
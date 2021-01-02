/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    
    void traverse(TreeNode* original, TreeNode* clone, TreeNode* target) {
        if (!original) {
            return;
        }
        
        if (original->val == target->val) {
            ans = clone;
            return;
        }
        
        if (original->left) {
            traverse(original->left, clone->left, target);
        }
        
        if (original->right) {
            traverse(original->right, clone->right, target);
        }
    }    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        traverse(original, cloned, target);
        return ans;
    }
};
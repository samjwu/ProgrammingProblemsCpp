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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = root->val;
        int pVal = p->val;
        int qVal = q->val;
        
        if (val < pVal && val < qVal) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (val > pVal && val > qVal) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        return root;
    }
};
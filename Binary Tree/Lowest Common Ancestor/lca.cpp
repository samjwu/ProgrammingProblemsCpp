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
        return recurse(root, p, q);
    }
    
private:
    TreeNode* recurse(TreeNode* n, TreeNode* p, TreeNode* q) {
        if (!n) {
            return nullptr;
        }
        
        if (n == p) {
            return p;
        }
        
        if (n == q) {
            return q;
        }
        
        TreeNode* l = recurse(n->left, p, q);
        TreeNode* r = recurse(n->right, p, q);
        
        if (l && r) {
            return n;
        } else if (l) {
            return l;
        } else if (r) {
            return r;
        }
        
        return nullptr;
    }
};
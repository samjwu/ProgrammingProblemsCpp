/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> recurse(TreeNode* n) {
        if (!n) {
            return make_pair(0, 0);
        }
        
        auto l = recurse(n->left);
        auto r = recurse(n->right);
        
        int rob = n->val + l.second + r.second;
        int leave = max(l.first, l.second) + max(r.first, r.second);
        
        return make_pair(rob, leave);
    }
    
    int rob(TreeNode* root) {
        pair<int, int> p = recurse(root);    
        return max(p.first, p.second);
    }
};
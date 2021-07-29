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
    map<TreeNode*, int> robmap;
    map<TreeNode*, int> leavemap;
    
    int recurse(TreeNode* n, bool parentrobbed) {
        if (!n) {
            return 0;
        }
        
        int ans;
        if (parentrobbed) {
            if (robmap.count(n) == 1) {
                return robmap[n];
            }
            
            ans = recurse(n->left, false) + recurse(n->right, false);
            robmap[n] = ans;
        } else {
            if (leavemap.count(n) == 1) {
                return leavemap[n];
            }
            
            int rob = n->val + recurse(n->left, true) + recurse(n->right, true);
            int leave = recurse(n->left, false) + recurse(n->right, false);
            ans = max(rob, leave);
            leavemap[n] = ans;
        }
        
        return ans;
    }
    
    int rob(TreeNode* root) {
        return recurse(root, false);
    }
};
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
    int getdiff(TreeNode* root, int minv, int maxv) {
        if (!root) {
            return maxv - minv;
        }
        
        minv = min(minv, root->val);
        maxv = max(maxv, root->val);
        int l = getdiff(root->left, minv, maxv);
        int r = getdiff(root->right, minv, maxv);
        return max(l, r);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int minv = root->val;
        int maxv = root->val;
        int ans = getdiff(root, minv, maxv);
        return ans;
    }
};
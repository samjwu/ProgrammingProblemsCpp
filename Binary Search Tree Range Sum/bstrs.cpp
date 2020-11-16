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
    int ans;
    
    void traverse(TreeNode* n, int l, int h) {
        if (!n) {
            return;
        }
        
        if (n->left) {
            traverse(n->left, l , h);
        }
        if (n->val >= l && n->val <= h) {
            ans += n->val;
        }
        if (n->right) {
            traverse(n->right, l , h);
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans = 0;
        traverse(root, low, high);
        return ans;
    }
};
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
    
    int postorder(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int l = postorder(root->left);
        int r = postorder(root->right);
        this->ans += abs(l - r);
        
        return root->val + l + r;
    }
    
    int findTilt(TreeNode* root) {
        this->ans = 0;
        postorder(root);
        return this->ans;
    }
};
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
    int getDepth(TreeNode* n) {
        if (!n) {
            return 0;
        }
        
        return max(getDepth(n->left), getDepth(n->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        
        return abs(right - left) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
};
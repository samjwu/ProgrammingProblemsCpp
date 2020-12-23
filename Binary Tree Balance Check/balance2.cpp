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
        
        int left = getDepth(n->left);
        if (left == -1) {
            return -1;
        }
        
        int right = getDepth(n->right);
        if (right == -1) {
            return -1;
        }
        
        if (abs(right - left) > 1) {
            return -1;
        }
        
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }
};
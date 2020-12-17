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
    bool isValid(TreeNode* n, int* low, int* high) {
        if (!n) {
            return true;
        }
        
        if ((low != nullptr && n->val <= *low) || (high != nullptr && n->val >= *high)) {
            return false;
        }
        
        return isValid(n->left, low, &n->val) && isValid(n->right, &n->val, high);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }
};
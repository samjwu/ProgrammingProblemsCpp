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
    int *prev = nullptr;
    
    bool inOrder(TreeNode* n) {
        if (!n) {
            return true;
        }
        
        if (!inOrder(n->left)) {
            return false;
        }
        
        if (prev && *prev >= n->val) {
            return false;
        }
        prev = &n->val;
        
        if (!inOrder(n->right)) {
            return false;
        }
        
        return true;
    }   
    
    bool isValidBST(TreeNode* root) {
        return inOrder(root);
    }
};
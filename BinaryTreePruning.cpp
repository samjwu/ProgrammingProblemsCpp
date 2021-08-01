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
    TreeNode* pruneTree(TreeNode* root) {
        if (!hasOne(root)) {
            return nullptr;
        }

        return root;
    }
    
private:
    bool hasOne(TreeNode* n) {
        if (!n) {
            return false;
        }
        
        bool hasLeft = hasOne(n->left);
        bool hasRight = hasOne(n->right);
        
        if (!hasLeft) {
            n->left = nullptr;
        }
        
        if (!hasRight) {
            n->right = nullptr;
        }
        
        return n->val == 1 || hasLeft || hasRight;
    }
};
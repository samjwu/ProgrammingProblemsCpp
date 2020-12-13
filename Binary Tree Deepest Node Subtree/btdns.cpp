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
    int maxDepth = 0;
    map<TreeNode*, int> depths;
    
    void setDepth(TreeNode* n, int depth) {
        if (!n) {
            return;
        }
        
        maxDepth = max(maxDepth, depth);
        depths[n] = depth;
        
        if (n->left) {
            setDepth(n->left, depth + 1);
        }
        if (n->right) {
            setDepth(n->right, depth + 1);
        }
    }
    
    TreeNode* getAnswer(TreeNode* n) {
        if (!n) {
            return nullptr;
        }
        
        if (depths[n] == maxDepth) {
            return n;
        }
        
        TreeNode* left = getAnswer(n->left);
        TreeNode* right = getAnswer(n->right);
        
        if (left && right) {
            return n;
        }
        if (left) {
            return left;
        }
        if (right) {
            return right;
        }
        
        return nullptr;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        setDepth(root, 0);
        return getAnswer(root);
    }
};
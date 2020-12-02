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
    void traverse(TreeNode* n, int depth, int& maximumDepth) {
        if (!n) {
            return;
        }
        
        maximumDepth = max(maximumDepth, depth + 1);
        
        if (n->left) {
            traverse(n->left, depth + 1, maximumDepth);
        }
        
        if (n->right) {
            traverse(n->right, depth + 1, maximumDepth);
        }
    }
    
    int maxDepth(TreeNode* root) {
        int maximumDepth = 0;
        traverse(root, 0, maximumDepth);
        return maximumDepth;
    }
};
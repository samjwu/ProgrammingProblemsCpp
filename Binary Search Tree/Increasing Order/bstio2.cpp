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
    TreeNode* newTree;
    
    void traverse(TreeNode* n) {
        if (!n) {
            return;
        }
        
        traverse(n->left);
        n->left = nullptr;
        newTree->right = n;
        newTree = newTree->right;
        traverse(n->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        newTree = new TreeNode();
        TreeNode* rootParent = newTree;
        traverse(root);
        
        return rootParent->right;
    }
};
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
    void traverse(TreeNode* n, vector<int>& newTree) {
        if (!n) {
            return;
        }
        
        traverse(n->left, newTree);
        newTree.push_back(n->val);
        traverse(n->right, newTree);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> newTree;
        traverse(root, newTree);
        
        TreeNode* newRootParent = new TreeNode();
        TreeNode* node = newRootParent;
        for (int val : newTree) {
            node->right = new TreeNode(val);
            node = node->right;
        }
        
        return newRootParent->right;
    }
};
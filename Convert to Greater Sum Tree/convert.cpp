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
private:
    int cumulativeSum = 0;
    
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root) {
            convertBST(root->right);
            
            cumulativeSum += root->val;
            root->val = cumulativeSum;
            
            convertBST(root->left);
        }
        
        return root;
    }
};
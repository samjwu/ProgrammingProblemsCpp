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
    int depth = 0;
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return depth;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return depth + 1;
        }
        if (min(minDepth(root->left), minDepth(root->right)) > 0) {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
        return 1 + max(minDepth(root->left), minDepth(root->right));
    }
};
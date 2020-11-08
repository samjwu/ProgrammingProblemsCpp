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
    void postorder(TreeNode* root, int* acc) {
        if (!root) {
            return;
        }
        
        if (!root->left && !root->right) {
            return;
        } else if (!root->left) {
            postorder(root->right, acc);
            root->val += root->right->val;
            *acc += abs(root->right->val);
        } else if (!root->right) {
            postorder(root->left, acc);
            root->val += root->left->val;
            *acc += abs(root->left->val);
        } else {
            postorder(root->left, acc);
            postorder(root->right, acc);
            root->val += root->left->val + root->right->val;
            *acc += abs(root->left->val - root->right->val);
        }
    }
    
    int findTilt(TreeNode* root) {
        int acc = 0;
        postorder(root, &acc);
        return acc;
    }
};
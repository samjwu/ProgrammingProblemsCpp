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
    stack<TreeNode*> stk;
    
    bool isValidBST(TreeNode* root) {
        TreeNode* n = root;
        int *prev = nullptr;
        
        while(!stk.empty() || n) {
            while(n) {
                stk.push(n);
                n = n->left;
            }
            
            n = stk.top();
            stk.pop();
            
            if (prev && *prev >= n->val) {
                return false;
            }
            
            prev = &n->val;
            n = n->right;
        }
        
        return true;
    }
};
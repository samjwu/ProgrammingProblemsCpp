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
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) {
            return root;
        }
        
        int sum = 0;
        TreeNode* n = root;
        stack<TreeNode*> stk;
        
        while (n || !stk.empty()) {
            while (n) {
                stk.push(n);
                n = n->right;
            }
            
            n = stk.top();
            stk.pop();
            
            sum += n->val;
            n->val = sum;
            
            n = n->left;
        }
        
        return root;
    }
};
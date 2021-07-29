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
    stack<int*> lowVals;
    stack<int*> highVals;
    
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        TreeNode* n;
        int *low = nullptr, *high = nullptr;
        
        stk.push(root);
        lowVals.push(low);
        highVals.push(high);
        
        while (!stk.empty()) {
            n = stk.top();
            stk.pop();
            low = lowVals.top();
            lowVals.pop();
            high = highVals.top();
            highVals.pop();
            
            if (!n) {
                continue;
            }
            
            if (low && n->val <= *low) {
                return false;
            }
            
            if (high && n->val >= *high) {
                return false;
            }
            
            stk.push(n->left);
            lowVals.push(low);
            highVals.push(&n->val);
            
            stk.push(n->right);
            lowVals.push(&n->val);
            highVals.push(high);
        }
        
        return true;
    }
};
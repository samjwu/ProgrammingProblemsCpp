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
    vector<int> ans;
    int idx = 0;
    
    bool preorder(TreeNode* n, vector<int>& v) {
        if (!n) {
            return true;
        }
        
        if (n->val != v[idx++]) {
            return false;
        }
        
        if (n->left && n->left->val != v[idx]) {
            ans.push_back(n->val);
            swap(n->left, n->right);
        }
        
        return preorder(n->left, v) && preorder(n->right, v);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (preorder(root, voyage) == true) {
            return ans;
        }
        
        return {-1};
    }
};
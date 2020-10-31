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
    vector<pair<TreeNode*, TreeNode*>> v;
    TreeNode* parent = NULL;
    
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }    
        
        dfs(root->left);
        if (parent && parent->val > root->val) {
            v.push_back({parent, root});
        }
        parent = root;
        dfs(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        if (v.size() == 1) {
            swap(v[0].first->val, v[0].second->val);
        }
        if (v.size() == 2) {
            swap(v[0].first->val, v[1].second->val);
        }
    }
};
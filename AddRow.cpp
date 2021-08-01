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
    TreeNode* newTree(TreeNode* root, int v) {
        TreeNode* r = new TreeNode(v);
        r->left = root;
        return r;
    }
    
    void getList(TreeNode* root, int curr, int d, vector<TreeNode*>& list) {
        if (!root) {
            return;
        }
        
        if (curr == d-1) {
            list.push_back(root);
        }
        
        getList(root->left, curr+1, d, list);
        getList(root->right, curr+1, d, list);
    }
    
    TreeNode* addRow(TreeNode* root, int v, int d) {
        vector<TreeNode*> listDMinus1;
        getList(root, 1, d, listDMinus1);
        
        for (TreeNode* n: listDMinus1) {
            TreeNode* newLeft = new TreeNode(v);
            if (n->left) {
                TreeNode* oldLeft = n->left;
                newLeft->left = oldLeft;
            }
            n->left = newLeft;
            
            TreeNode* newRight = new TreeNode(v);
            if (n->right) {
                TreeNode* oldRight = n->right;
                newRight->right = oldRight;
            }
            n->right = newRight;
        }
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* r = newTree(root, v);
            return r;
        }
        addRow(root, v, d);
        return root;
    }
};
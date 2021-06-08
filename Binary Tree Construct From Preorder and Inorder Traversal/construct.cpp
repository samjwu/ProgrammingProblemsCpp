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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        preorderIdx = 0;
        
        for (int i=0; i<n; i++) {
            inorderIdx[inorder[i]] = i;
        }
        
        return arrToTree(preorder, 0, n-1);
    }
    
private:
    int n;
    int preorderIdx;
    unordered_map<int, int> inorderIdx; // val to idx
    
    TreeNode* arrToTree(vector<int>& preorder, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        
        int rootVal = preorder[preorderIdx++];
        TreeNode* root = new TreeNode(rootVal);
        
        root->left = arrToTree(preorder, l, inorderIdx[rootVal]-1);
        root->right = arrToTree(preorder, inorderIdx[rootVal]+1, r);
        
        return root;
    }
};
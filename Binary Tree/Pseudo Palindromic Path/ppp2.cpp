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
    int ans = 0;
    int path;
    
    bool isPseudoPalindrome(int path) {
        if (path & (path - 1)) {
            return false;
        }
        
        return true;
    }
    
    void dfs(TreeNode* n) {
        path ^= 1 << n->val;

        if (!n->left && !n->right && isPseudoPalindrome(path)) {
            ans++;
        }

        if (n->left) {
            dfs(n->left);
        }

        if (n->right) {
            dfs(n->right);
        }

        path ^= 1 << n->val;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        dfs(root);
        
        return ans;
    }
};
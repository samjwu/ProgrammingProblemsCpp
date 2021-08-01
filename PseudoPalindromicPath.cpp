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
    vector<int> path;
    
    bool isPseudoPalindrome(vector<int>& path) {
        int oddParity = 0;
        map<int, int> parity;
        
        for (int nodeVal : path) {
            parity[nodeVal]++;
        }
        
        for (auto pair : parity) {
            if (pair.second % 2 == 1) {
                oddParity++;
            }
        }
        
        return oddParity <= 1;
    }
    
    void dfs(TreeNode* n) {
        path.push_back(n->val);

        if (!n->left && !n->right && isPseudoPalindrome(path)) {
            ans++;
        }

        if (n->left) {
            dfs(n->left);
        }

        if (n->right) {
            dfs(n->right);
        }

        path.pop_back();
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        dfs(root);
        
        return ans;
    }
};
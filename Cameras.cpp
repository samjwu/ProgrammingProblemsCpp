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
    int minCameraCover(TreeNode* root) {
        int rootState = dfs(root);
        
        if (rootState == UNCOVERED) {
            return ans + 1;
        }
        
        return ans;
    }
    
private:
    int ans = 0;
    enum NodeStates {UNCOVERED, CAMERA, COVERED};
    
    int dfs(TreeNode* n) {
        if (!n) {
            return COVERED;
        }    
        
        int leftState = dfs(n->left);
        int rightState = dfs(n->right);
        
        if (leftState == UNCOVERED || rightState == UNCOVERED) {
            ans++;
            return CAMERA;
        }
        
        if (leftState == CAMERA || rightState == CAMERA) {
            return COVERED;
        }
        
        return UNCOVERED;
    }
};
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
    void traverse(TreeNode* n, int depth) {
        if (!n) {
            return;
        }
        
        maxDepth = max(maxDepth, depth);
        depthSum[depth] += n->val;
        
        traverse(n->left, depth + 1);
        traverse(n->right, depth + 1);
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
        traverse(root, 1);
        return depthSum[maxDepth];
    }
    
private:
    unordered_map<int, int> depthSum;
    int maxDepth = 0;
};
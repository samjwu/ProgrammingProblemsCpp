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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        if (!root) {
            return ans;
        }
        
        queue<TreeNode*> level;
        level.push(root);
        TreeNode* currNode;
        int levelNodes;
        
        while (level.size() > 0) {
            ans.push_back(level.back()->val);
            
            levelNodes = level.size();
            
            while (levelNodes > 0) {
                currNode = level.front();
                level.pop();
                
                if (currNode->left) {
                    level.push(currNode->left);
                }
                
                if (currNode->right) {
                    level.push(currNode->right);
                }
                
                levelNodes--;
            }
        }
        
        return ans;
    }
};
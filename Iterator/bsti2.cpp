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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        buildStack(root);
    }
    
    int next() {
        TreeNode* n = stk.top();
        stk.pop();
        
        if (n->right) {
            buildStack(n->right);
        }
        
        return n->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    
private:
    stack<TreeNode*> stk;
    
    void buildStack(TreeNode* n) {
        while (n) {
            stk.push(n);
            n = n->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    
    void traverse(Node* n) {
        if (!n) {
            return;
        }
        
        ans.push_back(n->val);
        
        for (auto child: n->children) {
            traverse(child);
        }
    }
    
    vector<int> preorder(Node* root) {
        traverse(root);
        return ans;
    }
};
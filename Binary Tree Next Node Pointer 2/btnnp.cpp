/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    queue<Node*> q;
    
    void traverse(Node* root) {
        if (!root) {
            return;
        }
        
        q.push(root);
        
        int level = 1;
        int levelNodes = q.size();
        
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            
            if (n->left) {
                q.push(n->left);
            }
            if (n->right) {
                q.push(n->right);
            }
            
            levelNodes--;
            
            if (levelNodes == 0) {
                n->next = nullptr;
                level++;
                levelNodes = q.size();
            } else {
                n->next = q.front();
            }
        }
    }
    
    Node* connect(Node* root) {
        traverse(root);
        return root;
    }
};
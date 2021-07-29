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
    bool isEnd(int count) {
        while (count > 1) {
            if (count % 2 != 0) {
                return false;
            }
            count /= 2;
        }   
        return true;
    }
    
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        Node *n;
        int lvl = 1;
        int count = 0;
        while (!q.empty()) {
            n = q.front();
            q.pop();
            count++;
            
            if (!q.empty() && !isEnd(count + 1)) {
                n->next = q.front();
            }
            
            if (n->left) {
                q.push(n->left);
                q.push(n->right);
            }
        }
        
        return root;
    }
};
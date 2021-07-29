/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> memo;
    
    Node* cloneGraph(Node* node) {
        memo[nullptr] = nullptr;
        if (memo.count(node) > 0) {
            return memo[node];
        }
        
        Node *clone = new Node(node->val);
        memo[node] = clone;
        for (Node* neighbor:node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return clone;
    }
};
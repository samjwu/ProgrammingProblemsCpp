/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> nodeMap;
        
        Node* ptr = head;
        Node* copyPseudoHead = new Node(0);
        Node* copyPtr = copyPseudoHead;
        
        while (ptr) {
            nodeMap[ptr] = new Node(ptr->val);
            copyPtr->next = nodeMap[ptr];
            
            ptr = ptr->next;
            copyPtr = copyPtr->next;
        }
        
        ptr = head;
        copyPtr = copyPseudoHead->next;
        
        while (ptr) {
            copyPtr->random = nodeMap[ptr->random];
            
            ptr = ptr->next;
            copyPtr = copyPtr->next;
        }
        
        return copyPseudoHead->next;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sumNodes(ListNode* l1, ListNode* l2, int& carry) {
        if (!l1 && !l2) {
            return nullptr;
        }
        
        ListNode *n = new ListNode(-1);
        n->next = sumNodes(l1->next, l2->next, carry);
        
        n->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        
        return n;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        while (p1 || p2) {
            if (!p1) {
                ListNode *n = new ListNode(0);
                n->next = l1;
                l1 = n;
                p2 = p2->next;
            } else if (!p2) {
                ListNode *n = new ListNode(0);
                n->next = l2;
                l2 = n;
                p1 = p1->next;
            } else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        int carry = 0;
        ListNode *pseudohead = new ListNode(-1);
        pseudohead->next = sumNodes(l1, l2, carry);
        if (carry != 0) {
            ListNode *n = new ListNode(carry);
            n->next = pseudohead->next;
            pseudohead->next = n;
        }
        
        return pseudohead->next;
    }
};
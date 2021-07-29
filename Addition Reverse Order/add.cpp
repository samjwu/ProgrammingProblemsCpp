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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n = new ListNode();
        ListNode* pseudoHead = n;
        int carry = 0;
        int sum = 0;
        
        while (l1 && l2) {
            sum = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            n->next = new ListNode(sum);
            n = n->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            sum = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            n->next = new ListNode(sum);
            n = n->next;
            l1 = l1->next;
        }
        
        while (l2) {
            sum = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            n->next = new ListNode(sum);
            n = n->next;
            l2 = l2->next;
        }
        
        while (carry) {
            sum = (carry) % 10;
            carry = (carry) / 10;
            n->next = new ListNode(sum);
            n = n->next;
        }
        
        return pseudoHead->next;
    }
};
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
        ListNode *pseudohead = new ListNode(-1);
        ListNode *head = pseudohead;
        int carry = 0;
        while (l1 && l2) {
            ListNode *n = new ListNode();
            n->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            head->next = n;
            head = n;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            ListNode *n = new ListNode();
            n->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            head->next = n;
            head = n;
            l1 = l1->next;
        }
        while (l2) {
            ListNode *n = new ListNode();
            n->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            head->next = n;
            head = n;
            l2 = l2->next;
        }
        if (carry) {
            ListNode *n = new ListNode(carry);
            head->next = n;
        }
        return pseudohead->next;
    }
};
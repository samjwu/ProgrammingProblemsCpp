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
    ListNode* swapPairs(ListNode* head) {
        ListNode **doublePointer = &head;
        
        while (*doublePointer && (*doublePointer)->next) {
            ListNode *n1 = *doublePointer;
            ListNode *n2 = n1->next;
            
            n1->next = n2->next;
            n2->next = n1;
            *doublePointer = n2;
            
            doublePointer = &(n1->next);
        }
        
        return head;
    }
};
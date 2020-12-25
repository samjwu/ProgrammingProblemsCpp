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
    void swap(ListNode* n1, ListNode* n2) {
        if (n2->next && n2->next->next) {
            n1->next = n2->next->next;
        } else {
            n1->next = n2->next;
        }
        n2->next = n1;
    }
    
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* newhead = head->next;
        
        while (head && head->next) {
            ListNode* n1 = head;
            ListNode* n2 = head->next;
            head = head->next->next;
            swap(n1, n2);
        }
        
        return newhead;
    }
};
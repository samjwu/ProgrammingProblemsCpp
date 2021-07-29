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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *a = head, *b = head, *prev;
        
        for (int i=0; i<n; i++) {
            b = b->next;
        }
        
        while (b) {
            prev = a;
            a = a->next;
            b = b->next;
        }
        
        if (!prev) {
            return head->next;
        }
        
        prev->next = prev->next->next;
        return head;
    }
};
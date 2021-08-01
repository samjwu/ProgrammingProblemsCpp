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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }
        
        int counter = 0;
        ListNode* beforeHead = new ListNode();
        beforeHead->next = head;
        ListNode *prev = beforeHead, *curr = beforeHead, *next;
        
        while (curr = curr->next) {
            counter++;
        }
        
        while (counter >= k) {
            curr = prev->next;
            next = curr->next;
            
            for (int i=1; i<k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            
            prev = curr;
            counter -= k;
        }
        
        return beforeHead->next;
    }
};
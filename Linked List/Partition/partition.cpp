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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prev = new ListNode(0);
        ListNode* next = new ListNode(0);
        ListNode* prevHead = prev;
        ListNode* nextHead = next;
        
        while (head) {
            if (head->val < x) {
                prev->next = head;
                prev = prev->next;
            } else {
                next->next = head;
                next = next->next;
            }
            
            head = head->next;
        }
        
        next->next = nullptr;
        
        prev->next = nextHead->next;
         
        return prevHead->next;
    }
};
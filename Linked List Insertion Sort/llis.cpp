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
    ListNode* insertionSortList(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        
        ListNode *beforehead = new ListNode();
        ListNode *curr = head, *prev, *after;
        
        while (curr) {
            prev = beforehead;
            after = beforehead->next;
            
            while (after) {
                if (curr->val < after->val) {
                    break;
                }
                prev = after;
                after = after->next;
            }
            ListNode *currNext = curr->next;
            curr->next = after;
            prev->next = curr;
            
            curr = currNext;
        }
        
        return beforehead->next;
    }
};
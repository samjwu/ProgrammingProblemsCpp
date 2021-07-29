/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ans;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while (b) {
            a = headA;
            while (a) {
                if (a == b) {
                    return a;
                }
                a = a->next;
            }
            b = b->next;
        }
        
        return ans;
    }
};
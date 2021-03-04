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
        ListNode *pa = headA, *pb = headB;
        int la = 0, lb = 0;
        
        while (pa) {
            la++;
            pa = pa->next;
        }
        while (pb) {
            lb++;
            pb = pb->next;
        }
        
        pa = headA;
        pb = headB;
        
        if (la > lb) {
            int diff = la - lb;
            while (diff) {
                pa = pa->next;
                diff--;
            }
        } else {
            int diff = lb - la;
            while (diff) {
                pb = pb->next;
                diff--;
            }
        }
        
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
        }
        
        return pa;
    }
};
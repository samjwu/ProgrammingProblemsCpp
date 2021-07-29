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
        set<ListNode*> nodes;
        ListNode *ans = nullptr;
        while (headA) {
            nodes.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (nodes.count(headB) > 0) {
                ans = headB;
                break;
            }
            headB = headB->next;
        }
        return ans;
    }
};
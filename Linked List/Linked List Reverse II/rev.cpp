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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) {
            return nullptr;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i=1; i<left; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* revHead = prev;
        ListNode* revTail = curr;
        for (int i=left; i<=right; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        if (revHead) {
            revHead->next = prev;
        } else {
            head = prev;
        }
        revTail->next = curr;
        
        return head;
    }
};
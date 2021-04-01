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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* rev = nullptr;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* temp = rev;
            rev = slow;
            slow = slow->next;
            rev->next = temp;
        }
        
        if (fast) {
            slow = slow->next;
        }
        
        while (rev && rev->val == slow->val) {
            slow = slow->next;
            rev = rev->next;
        }
        
        return !rev;
    }
};
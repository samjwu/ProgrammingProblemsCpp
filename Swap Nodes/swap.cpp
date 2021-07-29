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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* node = head;
        while (node) {
            n++;
            node = node->next;
        }
        
        int l = n - k + 1;
        ListNode *swap1, *swap2;
        n = 0;
        node = head;
        while (node) {
            n++;
            if (n == k) {
                swap1 = node;
            }
            if (n == l) {
                swap2 = node;
            }
            node = node->next;
        }
        
        int temp = swap2->val;
        swap2->val = swap1->val;
        swap1->val = temp;
        
        return head;
    }
};
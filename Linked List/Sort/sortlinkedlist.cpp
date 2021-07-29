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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        vector<int> num;
        ListNode* node = head;
        while (node != nullptr) {
            num.push_back(node->val);
            node = node->next;
        }
        sort(num.begin(), num.end());
        
        node = head;
        for (int i=0; i<num.size(); i++) {
            node->val = num[i];
            node = node->next;
        }
        
        return head;
    }
};
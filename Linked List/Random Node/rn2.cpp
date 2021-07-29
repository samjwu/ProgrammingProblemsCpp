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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;    
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans = 0;
        int scope = 1;
        
        ListNode* node = this->head;
        while (node) {
            if ((rand() / (double) RAND_MAX) < (1.0 / scope)) {
                ans = node->val;
            }
            scope++;
            node = node->next;
        }
        
        return ans;
    }
    
private:
    ListNode* head;
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
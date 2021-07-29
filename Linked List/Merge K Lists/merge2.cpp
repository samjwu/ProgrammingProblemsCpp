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
    struct compare {
        bool operator()(ListNode* n1, ListNode* n2) {
            return n1->val >= n2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        ListNode pseudoHead(0);
        ListNode* ptr = &pseudoHead;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            ptr->next = node;
            ptr = ptr->next;
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return pseudoHead.next;
    }
};
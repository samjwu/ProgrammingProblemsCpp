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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        
        if (!l2) {
            return l1;
        }
        
        ListNode* head;
        
        if (l1->val >= l2->val) {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        } else {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        if (k == 0) {
            return nullptr;
        }
        
        while (k != 1) {
            int i = 0;
            int j = k-1;

            while (i < j) {
                lists[i] = mergeTwoLists(lists[i], lists[j]);
                i++;
                j--;
                
                if (i >= j) {
                    k = j+1;
                }
            }
        }
        
        return lists[0];
    }
};
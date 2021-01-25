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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        
        for (int i = 0; i < lists.size(); i++) {
            while (lists[i] != nullptr) {
                nums.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        
        sort(nums.begin(), nums.end());
        
        ListNode* pseudoHead = new ListNode();
        ListNode* node = pseudoHead;
        for (int num : nums) {
            node->next = new ListNode(num);
            node = node->next;
        }
        
        return pseudoHead->next;
    }
};
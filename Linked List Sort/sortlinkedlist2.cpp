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
    ListNode* get_middle(ListNode* head) {        
        ListNode* before_middle = nullptr;
        while (head != nullptr && head->next != nullptr) {
            if (before_middle == nullptr) {
                before_middle = head;
            } else {
                before_middle = before_middle->next;
            }
            head = (head->next)->next;
        }
        
        ListNode* middle = before_middle->next;
        before_middle->next = nullptr;
        
        return middle;
    }
    
    ListNode* merge(ListNode* left_list, ListNode* right_list) {
        ListNode node;
        ListNode* fake_head = &node;
        while (left_list != nullptr && right_list != nullptr) {
            if (left_list->val < right_list->val) {
                fake_head->next = left_list;
                left_list = left_list->next;
            } else {
                fake_head->next = right_list;
                right_list = right_list->next;
            }
            fake_head = fake_head->next;
        }
        
        if (left_list != nullptr) {
            fake_head->next = left_list;
        } else {
            fake_head->next = right_list;
        }

        return node.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* middle = get_middle(head);
        ListNode* left_list = sortList(head);
        ListNode* right_list = sortList(middle);
        
        return merge(left_list, right_list);
    }
};
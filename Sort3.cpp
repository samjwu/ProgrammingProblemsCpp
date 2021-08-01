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
    ListNode* end = new ListNode();
    ListNode* next_sub_list = new ListNode();

    int get_list_len(ListNode* head) {
        int count = 0;
        ListNode* node = head;
        while (node != nullptr) {
            node = node->next;
            count++;
        }
        return count;
    }

    ListNode* split(ListNode* start, int list_len) {
        ListNode* before_middle = start;
        ListNode* end = start->next;
        
        for (int i=1; i<list_len && (before_middle->next != nullptr || end->next != nullptr); i++) {
            if (end->next != nullptr) {
                if (end->next->next != nullptr) {
                    end = end->next->next;
                } else {
                    end = end->next;
                }
            }

            if (before_middle->next) {
                before_middle = before_middle->next;
            }
        }
       
        ListNode* middle = before_middle->next;
        next_sub_list = end->next;
        before_middle->next = nullptr;
        end->next = nullptr;
        
        return middle;
    }

    void merge(ListNode* left_list, ListNode* right_list) {
        ListNode fake_head;
        ListNode* new_end = &fake_head;

        while (left_list && right_list) {
            if (left_list->val < right_list->val) {
                new_end->next = left_list;
                left_list = left_list->next;
                new_end = new_end->next;
            } else {
                new_end->next = right_list;
                right_list = right_list->next;
                new_end = new_end->next;
            }
        }

        new_end->next = (left_list) ? left_list : right_list;
        
        while (new_end->next) {
            new_end = new_end->next;
        }
        
        end->next = fake_head.next;
        end = new_end;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
            
        int list_len = get_list_len(head);
        ListNode* start = head;
        ListNode fake_head;
        for (int i=1; i<list_len; i*=2) {
            end = &fake_head;

            while (start != nullptr) {
                if (start->next == nullptr) {
                    end->next = start;
                    break;
                }

                ListNode* middle = split(start, i);
                merge(start, middle);
                start = next_sub_list;
            }

            start = fake_head.next;
        }

        return fake_head.next;
    }
};

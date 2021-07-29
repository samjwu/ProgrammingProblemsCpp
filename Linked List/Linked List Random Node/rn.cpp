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
    ListNode* linkedList;
    int linkedListSize;
    
    Solution(ListNode* head) {
        this->linkedList = head;
        
        int size = 0;
        while (head) {
            head = head->next;
            size++;
        }
        this->linkedListSize = size;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        random_device randomDevice;
        mt19937 generator(randomDevice());
        uniform_int_distribution<int> distribution(0, this->linkedListSize - 1);
        int randomNum = distribution(generator);
        
        ListNode* node = this->linkedList;
        while (randomNum > 0) {
            node = node->next;
            randomNum--;
        }
        
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
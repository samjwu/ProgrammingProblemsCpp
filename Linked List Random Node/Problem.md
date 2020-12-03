### Description:

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.



### Example 1: 

// Init a singly linked list [1,2,3].  
ListNode head = new ListNode(1);  
head.next = new ListNode(2);  
head.next.next = new ListNode(3);  
Solution solution = new Solution(head);  

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.  
solution.getRandom();  
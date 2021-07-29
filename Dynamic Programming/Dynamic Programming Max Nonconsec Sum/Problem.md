### Description:

Given a list of non-negative integers, determine the maximum sum of nonconsecutive integers.

In essence, determine the maximum sum of integers that are chosen such that no two integers are right beside each other in the input array.



### Example 1:

Input: nums = [1,2,3,1]

Output: 4

Explanation: Select i=0 (value = 1) and then i=2 (value = 3).
             Total max sum = 1 + 3 = 4.

### Example 2:

Input: nums = [2,7,9,3,1]

Output: 12

Explanation: Select i={0, 2, 4} for values {2, 9, 1}
             Total max sum = 2 + 9 + 1 = 12.



### Constraints:

- 0 <= nums.length <= 100
- 0 <= nums[i] <= 400
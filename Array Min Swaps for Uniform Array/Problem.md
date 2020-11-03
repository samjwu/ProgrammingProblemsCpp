### Description:

Two arrays A and B contain n numbers in the range of 1 to 6 inclusive.
It is possible to swap A[i] and B[i], but only at i (it is not possible for example to swap A[0] with B[1]).
The desired goal is to swap A[i] and B[i] the minimum number of times such that A or B is a uniform array (all n numbers in A or B are equal or the same).

Return the minimum number of rotations to make all the values in A are the same, or all the values in B the same.
If it cannot be done, return -1.



### Example 1:

Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]

Output: 2

Explanation:

Swap A[i] and B[i] at i=1,3

### Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]

Output: -1

Explanation: 

It is not possible to make A or B uniform arrays through swaps.



### Constraints:

- 2 <= A.length == B.length <= 2 * 10^4
- 1 <= A[i], B[i] <= 6

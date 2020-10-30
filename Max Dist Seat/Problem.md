### Description:

Given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed), return the maximum distance to the closest person.

There is at least one empty seat, and at least one person sitting.



### Example 1:

Input: seats = [1,0,0,0,1,0,1]

Output: 2

Explanation: 

If the second open seat (i.e. seats[2]) is chosen, then the closest person has distance 2.

From any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

### Example 2:

Input: seats = [1,0,0,0]

Output: 3

Explanation: 

If the last seat (i.e. seats[3]) is chosen, the closest person is 3 seats away.

This is the maximum distance possible, so the answer is 3.

### Example 3:

Input: seats = [0,1]

Output: 1
 

Constraints:

- 2 <= seats.length <= 2 * 10^4
- seats[i] is 0 or 1.
- At least one seat is empty.
- At least one seat is occupied.
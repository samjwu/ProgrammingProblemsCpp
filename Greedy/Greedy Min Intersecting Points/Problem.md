### Description:

Given a list of ranges, determine the minimum number of points that cover/intersect all ranges.

For each item in the list, the provided input is the start and end coordinates of each range. The start is always smaller than the end.

A range with xstart and xend is covered/intersected by a point at x if xstart ≤ x ≤ xend.

Given a 2D array with points where points[i] = [xstart, xend], return the minimum number of points that will cover/intersect all ranges.

 

### Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]

Output: 2

Explanation: An example is x = [6,11]; x = 6 intersects [2,8] and [1,6], x = 11 intersects [10,16] and [7,12]

### Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]

Output: 4

### Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]

Output: 2

### Example 4:

Input: points = [[1,2]]

Output: 1

### Example 5:

Input: points = [[2,3],[2,3]]

Output: 1
 


### Constraints:

- 0 <= points.length <= 10^4
- points.length == 2
- -2^31 <= xstart < xend <= 2^31 - 1
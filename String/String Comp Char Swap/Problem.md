### Description:

Given two strings of lowercase letters, return true if two letters in the first string can be swapped to be equal to the second string. Otherwise, return false.

Swapping letters is defined as swapping the characters at A[i] and A[j] in string A where indices i and j are 0-indexed and i != j. For example, swapping the string "abcd" at i=0 and j=2 yields the result "cbad".


### Example 1:

Input: A = "ab", B = "ba"

Output: true

Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.

### Example 2:

Input: A = "ab", B = "ab"

Output: false

Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.

### Example 3:

Input: A = "aa", B = "aa"

Output: true

Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.

### Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"

Output: true

### Example 5:

Input: A = "", B = "aa"

Output: false



### Constraints:

- 0 <= A.length <= 20000
- 0 <= B.length <= 20000
- Input strings A and B consist of lowercase letters.
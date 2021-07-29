### Description:

Given an initial power of P, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed), the goal is to maximize total score by potentially playing each token in one of two ways:

- If current power is at least tokens[i], the ith token may be played face up, decreasing power by tokens[i] and increasing score by 1.

- If current score is at least 1, the ith token may be played face down, increasing power by tokens[i] and decreasing score by 1.

Each token may be played at most once and in any order. Not all tokens have to be played.

Return the largest possible score after playing any number of tokens.



### Example 1:

Input: tokens = [100], P = 50

Output: 0

Explanation: Playing the only token in the bag is impossible because there is too little power and too little score.

### Example 2:

Input: tokens = [100,200], P = 150

Output: 1

Explanation: After playing the 0th token (100) face up, power becomes 50 and score becomes 1.
There is no need to play the 1st token since it cannot be played cannot to add to the score.

### Example 3:

Input: tokens = [100,200,300,400], P = 200

Output: 2

Explanation: Play the tokens in this order to get a score of 2:
1. Play the 0th token (100) face up, power becomes 100 and score becomes 1.
2. Play the 3rd token (400) face down, power becomes 500 and score becomes 0.
3. Play the 1st token (200) face up, power becomes 300 and score becomes 1.
4. Play the 2nd token (300) face up, power becomes 0 and score becomes 2.
 


### Constraints:

- 0 <= tokens.length <= 1000
- 0 <= tokens[i], P < 10^4
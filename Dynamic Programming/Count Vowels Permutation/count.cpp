class Solution {
public:
    int countVowelPermutation(int n) {
        const int mod = pow(10, 9) + 7;
        map<pair<int, int>, long long> memo; // {i, j} == {len, vowel idx}

        for (int j=0; j<5; j++) {
            memo[{1, j}] = 1;
        }
        
        for (int i=2; i<=n; i++) {
            // aeiou = 01234
            memo[{i, 0}] = (memo[{i-1, 1}] + memo[{i-1, 2}] + memo[{i-1, 4}]) % mod; // a can follow e, i, u
            memo[{i, 1}] = (memo[{i-1, 0}] + memo[{i-1, 2}]) % mod; // e can follow a, i
            memo[{i, 2}] = (memo[{i-1, 1}] + memo[{i-1, 3}]) % mod; // i can follow e, o
            memo[{i, 3}] = (memo[{i-1, 2}]) % mod; // o can follow i
            memo[{i, 4}] = (memo[{i-1, 2}] + memo[{i-1, 3}]) % mod; // u can follow i, o
        }
        
        long long ans = 0;
        for (int j=0; j<5; j++) {
            ans += (memo[{n, j}] % mod);
        }
        
        return (int) (ans % mod);
    }
};
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }
        
        vector<bool> sieve(n, true);
        sieve[0] = false;
        sieve[1] = false;
        
        for (int i=2; i*i<n; i++) {
            if (sieve[i] == false) {
                continue;
            }
            
            for (int j=i*i; j<n; j+=i) {
                sieve[j] = false;
            }
        }
        
        return accumulate(sieve.begin(), sieve.end(), 0);
    }
};
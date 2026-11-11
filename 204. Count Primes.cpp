class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;

        // Sieve of Eratosthenes
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; (long long)i * i < n; ++i) {
            if (!isPrime[i]) continue;
            // Smaller multiples of i were already crossed out by smaller primes
            for (int j = i * i; j < n; j += i) isPrime[j] = false;
        }

        return count(isPrime.begin(), isPrime.end(), true);
    }
};

// https://leetcode.com/problems/super-ugly-number

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, 0);
        set<long long> candidates;  // Use a set to keep potential ugly numbers
        
        ugly[0] = 1;  // The first ugly number is always 1
        
        // Initialize the set with the first multiples of each prime
        for (int prime : primes) {
            candidates.insert(prime);
        }
        
        for (int i = 1; i < n; ++i) {
            ugly[i] = *candidates.begin();  // Get the smallest candidate
            candidates.erase(candidates.begin());  // Remove it from the set
            
            // Insert new potential ugly numbers into the set
            for (int prime : primes) {
                long long newUgly = static_cast<long long>(ugly[i]) * prime;
                if (newUgly > 0) {  // Ensure there is no overflow
                    candidates.insert(newUgly);
                }
            }
        }
        
        return ugly[n - 1];
    }
};

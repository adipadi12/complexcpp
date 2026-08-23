class Solution {
public:
    static const int MAX_VAL = 100001;
    int spf[MAX_VAL];

    // Precompute Smallest Prime Factors using Sieve of Eratosthenes
    void sieve() {
        for (int i = 1; i < MAX_VAL; ++i) spf[i] = i;
        for (int i = 2; i * i < MAX_VAL; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAX_VAL; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
    }

    // Helper to get distinct prime factors of a number using SPF
    vector<int> getPrimeFactors(int n) {
        vector<int> factors;
        while (n > 1) {
            int p = spf[n];
            factors.push_back(p);
            while (n % p == 0) n /= p;
        }
        return factors;
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        // Store the input midway as requested
        vector<int> copy = nums;
        
        sieve(); // Precompute SPF
        
        unordered_map<int, int> primeCounts; // Map: prime -> count in current window
        int distinctPrimes = 0;
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < copy.size(); ++right) {
            // Add nums[right] to the window
            int num = copy[right];
            vector<int> factors = getPrimeFactors(num);
            
            for (int p : factors) {
                if (primeCounts[p] == 0) {
                    distinctPrimes++;
                }
                primeCounts[p]++;
            }
            
            // Shrink window from left if distinct primes exceed k
            while (distinctPrimes > k) {
                int leftNum = copy[left];
                vector<int> leftFactors = getPrimeFactors(leftNum);
                
                for (int p : leftFactors) {
                    primeCounts[p]--;
                    if (primeCounts[p] == 0) {
                        distinctPrimes--;
                    }
                }
                left++;
            }
            
            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
class Solution {
public:
    double recursion(double x, long long n) { // dry run 2^3

        if (n == 0) {
            return 1;
        }

        double temp = recursion(x, n / 2); 
        /* 1: temp = recursion(2, 1)
            2: temp = recursion(2, 0)
        */ 

        if (n % 2 == 0) {
            return temp * temp; // returns 2*2
        }

        return x * temp * temp; // return 2 * recursion(2, 1) * recursion(2, 1) = 2 * 2 * 2
        // recursion(2, 1) = 2 * recursion(2,0) * recursion(2,0) = 2
    }

    double myPow(double x, int n) {

        long long N = llabs((long long)n); // absolute of long long to prevent integer overflow

        double ans = recursion(x, N);

        return n < 0 ? 1 / ans : ans; // if n < 0 return 1 / ans because x^-1 = 1/x
    }
};
class Solution {
public:

    long long power(int base, int n, int m) {
        long long ans = 1;

        for(int i = 0; i < n; i++) {
            ans *= base;

            if(ans > m)
                return ans;
        }

        return ans;
    }

    int nthRoot(int n, int m) {

        if(m == 0)
            return 0;

        int low = 1;
        int high = m;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            long long value = power(mid, n, m);

            if(value == m)
                return mid;

            if(value < m)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};
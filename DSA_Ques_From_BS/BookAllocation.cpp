#include <vector>
class Solution {
public:

    int findMaxElement(vector<int>& arr) {
        int max_val = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > max_val) {
                max_val = arr[i];
            }
        }

        return max_val;
    }

    long long findSumOfArray(vector<int>& arr) {
        long long sum = 0;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }

        return sum;
    }

    bool isAllocationPossible(vector<int>& arr, long long barrier, int k) {
        int students = 1;
        long long pages = 0;

        for(int i = 0; i < arr.size(); i++) {

            if(arr[i] > barrier)
                return false;

            if(pages + arr[i] > barrier) {
                students++;
                pages = arr[i];
            }
            else {
                pages += arr[i];
            }
        }

        return students <= k;
    }

    int findPages(vector<int>& arr, int k) {

        if(k > arr.size())
            return -1;

        long long low = findMaxElement(arr);
        long long high = findSumOfArray(arr);
        long long result = -1;

        while(low <= high) {

            long long mid = low + (high - low) / 2;

            if(isAllocationPossible(arr, mid, k)) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return (int)result;
    }
};
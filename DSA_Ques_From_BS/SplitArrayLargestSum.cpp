class Solution {
public:
    int findMinElement(vector<int>& arr){
        int n = arr.size(); // size calculated dynamically

        if(n==0) return 0; // empty array

        int min_val = arr[0];

        for(int i = 1; i < n; i++){
            if(arr[i] < min_val){
                min_val = arr[i];
            }
        }
        return min_val;
    }

    int findSumOfArray(vector<int>& arr){
        int sum = 0;
        if(arr.size() != 0){
            for(int i = 0; i < arr.size(); i++){
                sum += arr[i];
            }
        }
        return sum;
    }

    bool isAllocationPossible(vector<int>& arr, int barrier, int k){
        int allocates_to_ints = 1, quantity = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] > barrier) return false;
            if(quantity + arr[i] > barrier){
                allocates_to_ints++;
                quantity = arr[i];
            }
            else{
                quantity += arr[i];
            }
        }
        if(allocates_to_ints > k) return false;
        return true;
    }
    
    int minSum(vector<int> &arr, int k) {
        // code here
        int low = findMinElement(arr), high = findSumOfArray(arr), result = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(isAllocationPossible(arr, mid, k)){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return result;
    }
    
    int splitArray(vector<int>& nums, int k) {
        return minSum(nums, k);
    }
};
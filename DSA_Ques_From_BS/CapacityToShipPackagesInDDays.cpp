class Solution {
public:
    int findMaxElement(vector<int>& arr){
        int n = arr.size(); // size calculated dynamically

        if(n==0) return 0; // empty array

        int max_val = arr[0];

        for(int i = 1; i < n; i++){
            if(arr[i] > max_val){
                max_val = arr[i];
            }
        }
        return max_val;
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

    int totalDays(vector<int>& arr, int cap){
        int n = arr.size();
        int day = 1, load = 0; // on first day assume load is 0
        for(int i = 0; i < n; i++){
            if(load + arr[i] > cap){
                day++; // load for that day needs to be less than capacity
                load = arr[i]; // if not increase the days and make load for the next day to be the last array where we left off
            }
            else load += arr[i]; // else keep adding the load that can be added within capacity for a day
        }
        return day; // from this day returned
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = findMaxElement(weights), high = findSumOfArray(weights); // lowest weight capacity will always be the max element because capacity needs to be at least as much as the highest weight and highest weight capacity will always be the sum of all elements so all weight can be done in 1 day
        while(low <= high){
            int mid = (low+high)/2;
            int total_days = totalDays(weights, mid);
            if(total_days <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1; 
            }
        }
        return low; // regular binary search
    }
};
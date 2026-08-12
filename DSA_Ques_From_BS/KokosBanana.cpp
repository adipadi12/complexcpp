class Solution {
public:
    long long findMaxElement(vector<int>& arr){
        int n = arr.size(); // size calculated dynamically

        if(n==0) return 0; // empty array

        long long max_val = arr[0];

        for(int i = 1; i < n; i++){
            if(arr[i] > max_val){
                max_val = arr[i];
            }
        }
        return max_val;
    }

    long long totalHours(vector<int>& arr, int hourly){
        long long total_hours = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            total_hours += ceil((double)arr[i]/(double)hourly);
        }
        return total_hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        long long high = findMaxElement(piles); 
        while(low <= high){
            int mid = (low + high)/2;
            long long totalhrs = totalHours(piles, mid);
            if(totalhrs <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
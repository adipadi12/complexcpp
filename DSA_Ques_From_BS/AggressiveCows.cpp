class Solution {
  public:
    bool canWePlace(vector<int>& arr, int dist, int cows){
        int cntcows = 1, last = arr[0];
        int n = arr.size();
        for(int i = 1; i < n; i++){
            if(arr[i] - last >= dist){
                cntcows++;
                last = arr[i];
            }
        }
        if(cntcows >= cows) return true;
        else return false;
    }
  
    int aggressiveCows(vector<int> &arr, int cows) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int low = 0, high = arr[n-1] - arr[0];
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(canWePlace(arr,mid,cows) == true){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};
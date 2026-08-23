class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> arr;
        vector<int> nums_copy = nums;
        sort(nums_copy.begin(), nums_copy.end()); // we first sort the copy
        int n = nums_copy.size();

        int prev = lower - 1; // for comparing we take prev 1 less than lower
        // prev = 0
        for(int i = 0; i <= n; ++i){
            int curr;
            if(i == n){
                curr = upper + 1; 
            }
            else{
                if(nums_copy[i] < lower || nums_copy[i] > upper) continue;
                curr = nums_copy[i]; // curr = 3
            }

            if(curr == prev) continue;

            if(curr - prev >= 2){
                arr.push_back({prev+1, curr - 1}); // 1,2
            }

            prev = curr; // prev = 3
        }
        return arr;
    }

    // dry run [3,9,7] lower = 1 upper = 12
    // [1,2], []
}
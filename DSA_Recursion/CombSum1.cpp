class Solution {
public:
    void findComb(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds)
    { // index is current position, target is sum remaining, arr is candidates, ans is all possible subsequences, ds is current valid subsequence being built

        if(index == arr.size()) // all candidates exhausted
        {
            if(target == 0) // target exactly 0 then current combination is valid
            {
                ans.push_back(ds);
            }
            return;
        }
        // pickup element
        if(arr[index] <= target) // if current element doesn't exceed target add to ds
        {
            ds.push_back(arr[index]);
            findComb(index, target - arr[index], arr, ans, ds); // recurse again to check for base case / branch
            ds.pop_back(); // remember to pop ds after backtracking
        }
        findComb(index + 1, target, arr, ans, ds); // move to next candidate without picking current one, covers for when arr[index] > target
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }
};
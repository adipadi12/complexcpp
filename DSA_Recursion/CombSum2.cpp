class Solution {
public:
    void findComb(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds)
    {
        if(target == 0) // target exactly 0 then current combination is valid
        {
            ans.push_back(ds);  // no need to check for out of bounds because of for loop below      
            return;
        }
        
        // pickup element
        for(int i = index; i < arr.size(); i++) // pick arr[i] as next element
        {
            if(i > index && arr[i] == arr[i-1]) continue; // array is sorted and duplicates side by side so skipped
            if(arr[i] > target) break; // array sorted, every subsequent element will also be larger so we break
            ds.push_back(arr[i]); //pick arr[i]
            findComb(i + 1, target - arr[i], arr, ans, ds); // recurse with i+1
            ds.pop_back(); //backtrack
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort array
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort for easily eliminiating duplicates
        vector<vector<int>> ans;
        vector<int> sub_set;
        subsets(nums, 0, sub_set, ans); // adds subset to ans
        return ans;
    }
private:
    void subsets(vector<int>& nums, int index, vector<int>& sub, vector<vector<int>>& subs)
    {
        subs.push_back(sub); // empty subset pushed at first and then during every recursive call
        for(int j = index; j < nums.size(); j++)
        {
            if (j > index && nums[j] == nums[j - 1]) continue; // skip duplicate
            sub.push_back(nums[j]); // subset mein pushback current index
            subsets(nums, j+1, sub, subs); // recursive call for one index above
            sub.pop_back(); // pop subset
        }
    }
};
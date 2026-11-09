class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
            sub.push_back(nums[j]); // subset mein pushback current index
            subsets(nums, j+1, sub, subs); // recursive call for one index above
            sub.pop_back(); // pop subset
        }
    }
};
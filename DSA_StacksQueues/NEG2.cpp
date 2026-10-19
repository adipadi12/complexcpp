class Solution {
public:
    vector<int> nextGreaterElementsBruteForce(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < i + n; j++)
            {
                int ind = j % n;
                if(nums[ind] > nums[i])
                {
                    ans[i] = nums[ind];
                    break;
                }
            }
        }
        return ans;
    }
};

class SolutionOptimal {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = 2*n-1; i >= 0; i--) // double array iterate through it from last element to first
        {
            while(!st.empty() && st.top() <= nums[i % n])
            {
                st.pop(); // pop stack if top element smaller than the one in array
            }

            if(i < n)
            {
                if(!st.empty()) ans[i] = st.top();
                //ans[i] = st.empty() ? -1 : st.top(); // no need for modulo here we at main array
            }

            st.push(nums[i % n]); // at the end push current element to stack
        }
        return ans;
    }
};
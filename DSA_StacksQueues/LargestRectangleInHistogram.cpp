class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++) // iterates through bars
        {
            while(!st.empty() && heights[st.top()] > heights[i]) // checks if top of stack element is greater than element we are on. looking for nse
            {
                int element = st.top(); // store element
                st.pop(); // pop
                int nse = i; // potential nse
                int pse = st.empty() ? -1 : st.top(); // if not empty top of stack
                maxArea = max(heights[element] * (nse - pse - 1), maxArea); // keeps track of maxarea per iteration
            }
            st.push(i); // push to stack
        }
        while(!st.empty()){ // drains all remaining in stack
            int nse = heights.size();
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse-pse-1) * heights[element]);
        }
        return maxArea;
    }
};
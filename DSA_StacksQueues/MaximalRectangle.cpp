class Solution {
public:
    int largestHistogramArea(vector<int>& heights) {
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int maxArea = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> pSum(m, vector<int>(n, 0));

        // Build histogram heights for consecutive ones.
        for (int j = 0; j < n; j++) {
            int sum = 0;

            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == '1')
                    sum += 1;
                else
                    sum = 0;

                pSum[i][j] = sum;
            }
        }

        // Each row is a histogram.
        for (int i = 0; i < m; i++) {
            maxArea = max(
                maxArea,
                largestHistogramArea(pSum[i])
            );
        }

        return maxArea;
    }
};
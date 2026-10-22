class StockSpanner {
public:
    stack<pair<int, int>> st; // monotonic stack
    int ind;
    int ans;
    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind++; // current day index
        while(!st.empty() && st.top().first <= price) // not empty and value of top element <= price
        {
            st.pop(); // pop every entry <= today's value
        }
        ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind}); // push today's entry so it can serve as a boundary for future entries
        return ans;
    }
};
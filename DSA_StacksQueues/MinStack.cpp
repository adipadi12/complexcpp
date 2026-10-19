class MinStackO2NSpaceComplextiy {
    stack<pair<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) st.push({value, value});
        else st.push( {value, min(value, st.top().second)} );
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

class MinStack {
    stack<long> st;
    long mini = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty())
        {
            mini = (long)value;
            st.push((long)value);
        } 
        else 
        {
            if(value > (int)mini)
            {
                st.push((long) value);
            }
            else
            {
                st.push(2*(long)value - mini); // push this algorithmic value so last mini can be found
                mini = (long)value; //
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long oldMin = st.top();
        st.pop();
        if(oldMin < mini) mini = 2*mini - oldMin;
    }
    
    int top() {
        if(st.empty()) return -1;
        long oldMin = st.top();
        if(mini < oldMin) return (int)oldMin;
        return (int)mini;
    }
    
    int getMin() {
        return (int)mini;
    }
};
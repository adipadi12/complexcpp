class MyStack {
    queue<int> q;
    int s = q.size();
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        
        for(int i = 1; i < s - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};
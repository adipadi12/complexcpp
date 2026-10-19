class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                st.push(s[i]); // push opening bracks to stack
            }
            else
            {
                if(st.empty()) return false; // after pushing if empty then empty string
                
                char ch = st.top(); // top chose eg '(){()}' 
                st.pop();
                if(s[i] == ')' && ch == '(' // compares each closing with opening in stack and pops it
                    || s[i] == '}' && ch == '{'
                    || s[i] == ']' && ch == '[')
                    continue;
                
                else return false;
            }
        }
        return st.empty();
    }
};
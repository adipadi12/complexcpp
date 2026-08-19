class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int level = 0; // nesting level
        for(char ch: s){
            if(ch == '('){
                if(level > 0) res += ch; // we add to result when inside primitive
                level++; // increment level afterwards
            }
            if(ch == ')'){
                level--; // increment level before
                if(level > 0) res += ch; //add to res
            }
        }
        return res;
    }
};
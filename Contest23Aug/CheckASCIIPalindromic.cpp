class Solution {
public:
    string charToBinary(string str){
        string binary = "";
        for(char const c : str){
            binary += bitset<8>(c).to_string();
        }
        return binary;
    }
    bool isPalindromic(string s) {
        string str = charToBinary(s);
        reverse(str.begin(), str.end());
       
        return str == charToBinary(s);
    }
};
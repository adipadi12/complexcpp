class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        string word = "";
        for(int i = 0; i < s.size(); i++){
            if (s[i] != ' ')
            {
                word += s[i]; // add if space is not present to word
            }
            else if(!word.empty()){ // if we find a space and have a word collected
                arr.push_back(word); // push to string
                word = ""; // empty string
            }
        }
         // Push the last word if it exists
        if (!word.empty()) {
            arr.push_back(word);
        }

        reverse(arr.begin(), arr.end());

        string result = "";
        for(int i = 0; i < arr.size(); i++){
            result += arr[i];
            if(i < arr.size() - 1) { // add space if not before the last word
                result += " ";
            }
        }
        return result;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = s.size() - 1;
        while (i >= 0){ // right to left
            while(i >= 0 && s[i] == ' '){
                i--;
            }
            if(i < 0) break;
            int end = i; // mark end of current word
            while(i >= 0 && s[i] != ' '){
                i--;
            }
            string word = s.substr(i + 1, end - i); // creates a word from where i is rn to where end is
            if(!res.empty()){
                res += " ";
            }
            res += word;
        }
        return res;
    }
};
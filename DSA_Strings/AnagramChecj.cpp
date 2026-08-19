#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagramBF(string s, string t) {
        if(s.size() != t.size()) return false;

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        if (s == t) return true;
        return false;
    }
};

bool isAnagramOptimal(string s, string t) {
        if(s.size() != t.size()) return false;

        int arr[26] = {0}; // array for all lowercase english alphabets

        for(int i = 0; i < s.size(); i++){
            arr[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++){
            arr[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(arr[i] != 0) return false;
        }
        return true;
    }

int main(){
    Solution sol;

    string s = "Hannah";
    string t = "annahH";

    cout << isAnagramOptimal(s, t) << '\n';

    return 0;
}
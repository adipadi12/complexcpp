#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        string ans = s;
        for(int i = 0; i < n - 1; i++){
            ans[i] = s[i+1];
        }
        ans[n-1] = s[0];
        if(ans == goal) return true;
        else return false;
}

int main(){
    string s = "hi";
    string g = "ih";
    cout << rotateString(s,g) << "\n";
}

bool rotateStringBrute(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        for(int i = 0; i < n; i++){
            string ans = s.substr(i) + s.substr(0,i);
            if(ans == goal) return true;
        }
        return false;
    }

bool rotateStringOptimal(string& s, string& goal) {
    // Strings must be the same length to be rotations of each other
    if (s.length() != goal.length()) return false;
    
    // Concatenate s with itself and check if goal exists in it
    string doubledS = s + s;
    return doubledS.find(goal) != string::npos;
}
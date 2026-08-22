#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringBrute(string s) {
        int n = s.size();
        int maxlen = 0;
        string sub = "";
        for(int i = 0; i < n; i++){
            int hash[256] = {0};
            for(int j = i; j < n; j++){
                if(hash[s[j]] == 1) break; // if count of this char repeats break substring
                int len = j - i + 1;
                maxlen = max(len, maxlen);
                hash[s[j]] = 1;
            }
        }
        return maxlen;
    }
    int lengthOfLongestSubstringOptimal(string s) {
        int n = s.size();
        int maxlen = 0;

        vector<int> hash(256,-1); // intialize all elements to -1

        int l = 0, r = 0;
        while(r < n){
            if(hash[s[r]] != -1) // in the map
            {
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                    //only move l if it is already inside the window
                }
            }
            int len = r - l + 1;
            maxlen = max(len,maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }

    int main(){
        cout << lengthOfLongestSubstringOptimal("jhatuajhatua") << "\n";
    }
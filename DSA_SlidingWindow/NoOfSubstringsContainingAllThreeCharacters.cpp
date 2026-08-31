#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstringsBrute(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int hash[3] = {0};
            for(int j = i; j < n; j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3){
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int numberOfSubstringsOptimal(string s) {
        int n = s.size();
        int cnt = 0;
        int lastindex[3] = {-1, -1, -1};
        for(int i = 0; i < n; i++)
        {
            lastindex[s[i] - 'a'] = i;

            if(lastindex[0] != -1 && lastindex[1] != -1 && lastindex[2] != -1)
            {
                cnt = cnt + (1 + min(min(lastindex[0], lastindex[1]), lastindex[2]));
            }
        }
        return cnt;
    }
};

int main(){
    string nums = "bbabc";
    Solution sol;
    cout << sol.numberOfSubstringsOptimal(nums) << "\n";
    return 0;
}
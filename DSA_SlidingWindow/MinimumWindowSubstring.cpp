class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(), l = 0, r = 0, cnt = 0, sindex = -1, minlen = pow(10, 5);
        int hash[256] = {0};
        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }
        while(r < n){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
        
            while(cnt == m){
                if(r - l + 1 < minlen){
                    minlen = r - l + 1;
                    sindex = l;
                }
                // CORRECT:
                if(hash[s[l]] == 0) cnt--;
                hash[s[l]]++;  
                l++;
            }
            r++;
        }
    
        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};
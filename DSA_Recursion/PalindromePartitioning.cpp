class Solution {
public:
    vector<vector<string>> partition(string s) { 
        // dry run with aabb
        vector<vector<string>> result; // answer
        vector<string> path; // holds substrings of valid partitions
        palindromPartitionCheck(0, s, path, result); // partition being built off of 1st row
        // 0, aabb, path, result
        return result;
    }

    void palindromPartitionCheck(int index, string s, vector<string> &path, vector<vector<string>> &result)
    {
        if(index == s.size()) // if index reaches end entire string has been partitioned
        // 0 == 4 X
        {
            result.push_back(path); // push path to result
            return; // stop this branch
        }
        for(int i = index; i < s.size(); ++i) // loop
        // i == 0; i < 4
        {
            if(isPalindrome(s, index, i)) // if it is a palindrome
            // a-a 0-0 is a palindrome
            {
                path.push_back(s.substr(index, i - index + 1)); // add palindromic string to current path
                // a pushed to path
                palindromPartitionCheck(i + 1, s, path, result); // recurse
                path.pop_back(); // clear it for when it goes back
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};
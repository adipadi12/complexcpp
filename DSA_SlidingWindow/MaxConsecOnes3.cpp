class Solution {
public:
    int longestOnesBrute(vector<int>& nums, int k) {
        int maxlen = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int zeros = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == 0) zeros++;
                if(zeros <= k){
                    int len = j - i + 1;
                    maxlen = max(maxlen,len);
                }
                else break;
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int longestOnesBetter(vector<int>& nums, int k) {
        int maxlen = 0;
        int n = nums.size();
        int l = 0, r = 0, zeros = 0;
        while(r < n){
            if(nums[r] == 0){
                zeros++;
            }
            while(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                    l++;
                }
            }
            if(zeros <= k){
                int len = r - l + 1;
                maxlen = max(len, maxlen);
            }
            r++;
        }
        
        return maxlen;
    }
};

class Solution {
public:
    int longestOnesOptimal(vector<int>& nums, int k) {
        int maxlen = 0;
        int n = nums.size();
        int l = 0, r = 0, zeros = 0;
        while(r < n){
            if(nums[r] == 0){
                zeros++;
            }
            if(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            if(zeros <= k){
                int len = r - l + 1;
                maxlen = max(len, maxlen);
            }
            r++;
        }
        
        return maxlen;
    }
};

class Solution {
public:
    int longestOnesBetterThanOptimal(vector<int>& nums, int k) {
        int l = 0, r = 0, zeros = 0;
        
        for (r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) zeros++;
            
            // If zeros exceed k, shrink window from the left
            if (zeros > k) {
                if (nums[l] == 0) zeros--;
                l++;
            }
        }
        
        // The window size (r - l) is the maximum found because 'l' only increments
        // when necessary, effectively preserving the max width.
        // Note: In this specific optimized pattern, we return r - l because 
        // the loop finishes with r one step past the last element.
        return r - l; 
    }
};
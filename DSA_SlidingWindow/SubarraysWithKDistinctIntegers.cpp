#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayWithAnyK(vector<int>& nums, int k){
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;
        //if(k < 0) return 0; // check not required for this it seems
        while(r < nums.size()){ // r doesn't exceed size of nums
            mpp[nums[r]]++; // increase freq of number on rth index
            while(mpp.size() > k){ // if mpp exceeds k
                mpp[nums[l]]--; // reduce one freq of number at lth index
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]); // check if it is zero so remove if it is
                l++; // increment l
            }
            cnt += (r - l + 1); // this cnt is for all subarrays that can be made which is basically everything from l to r at that point
            r++; // increase r
        }
        return cnt; // cnt gives total subarrays in the range you want
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (subarrayWithAnyK(nums, k) - subarrayWithAnyK(nums, k-1)); // returning count of those <= k - <= k-1 gives only those == k
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1,3,4};
    int k = 3;
    cout << "Subarrays with K: " << s.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}
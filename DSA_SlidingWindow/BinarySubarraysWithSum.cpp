#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numGoals(vector<int>& a, int k){
        int l = 0, r = 0, sum = 0, cnt = 0;
        if(k < 0) return 0; // this is important for an edge case 
        while(r < a.size()){
            sum += a[r];
            while(sum > k){
                sum -= a[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (numGoals(nums, goal) - numGoals(nums, goal - 1));
    }
};

int main(){
    vector<int> nums = {1, 0, 1, 0, 1};
    Solution sol;
    cout << sol.numSubarraysWithSum(nums, 2) << "\n";
}
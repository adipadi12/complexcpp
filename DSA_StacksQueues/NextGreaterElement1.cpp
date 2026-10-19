class SolutionBrutestForce {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++)
        {
            // find nums1[i] in nums2
            int pos = -1;
            for(int k = 0; k < nums2.size(); k++){
                if(nums2[k] == nums1[i]) {
                    pos = k;
                    break;
                };
            }
            // search from right of pos to compare next greater
            for(int j = pos + 1; j < nums2.size(); j++)
            {
                if(nums2[j] > nums1[i]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1); // initialized nums1.size values to -1
        stack<int> st;
        unordered_map<int, int> m;
        for(int i = 0; i < nums2.size(); i++)
        {
            while(!st.empty() && st.top() <= nums2[i]){ //iterating through nums2
                m[st.top()] = nums2[i]; // hashmap of key value pair where key is the stack element
                st.pop(); // pop last element in stack
            }
            st.push(nums2[i]); // push element in stack
        }

        for(int i = 0; i < nums1.size(); i++)
        {
            if(m.count(nums1[i])){
                ans[i] = m[nums1[i]];
            }
        }
        return ans;
    } /*
    dry run 
        nums1 = [4, 1, 2]

        nums2 = [1, 3, 4, 2]

        st has 1 pushed to it, then map[1] = 3, 1 popped from stack, 3 pushed to stack.
        map[3] = 4, 3 popped from stack, 4 pushed to stack
        2 pushed to stack

        next for loop
        if map value for nums1[i] exists -> ans[i] = m[nums1[i]];
        rest values initialized to -1 so no change required
        
    */
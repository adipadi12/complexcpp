class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // vector instead of stack so it doesn't have to be reversed later
        for(int i = 0; i < asteroids.size(); i++)
        {
            if(asteroids[i] > 0) st.push_back(asteroids[i]); // push positive asteroids to vector
            else
            {
                while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) // last element of vector is > 0 && < abs(asteroids[i])
                {
                    st.pop_back(); // then pop that positive element from vector
                }
            
                if(!st.empty() && st.back() == abs(asteroids[i])) st.pop_back(); // if last element is equal to asteroids[i] even then pop the positive element from vector
                else if(st.empty() || st.back() < 0) st.push_back(asteroids[i]); // empty vector OR last element of vector less than 0 only then add negative number
            }
        }
        return st;
    }
};
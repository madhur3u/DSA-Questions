class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        // stack<int> st; // we can simulate stack in vector using pop back and back
        // satck simulated in vector so mem is used less 
        vector<int> st;
        
        // iterate in 
        for (int a : asteroids) {

            // push current element in satck
            st.push_back(a);

            // if there are 2 or more element and top is a negetive number
            // loop runs till condition is true
            while (st.size() > 1 && st.back() < 0) {

                // extract top two elements
                // if s2 means 2nd element also -ve we push el again and continue
                // as both -ve cannot have any result 
                int s1 = st.back(); st.pop_back();
                if (st.back() < 0){
                    st.push_back(s1);
                    break;
                }
                int s2 = st.back(); st.pop_back();

                // when we are here means s1 -ve ans s2 +ve so we check for both cases 
                // and push whichever is bigger
                // dont do anything for equal as we have already popped both  
                if (-s1 > s2)       st.push_back(s1);
                else if (-s1 < s2)  st.push_back(s2);
                
            }
        }
        // while (!st.empty()) ans.push_back(st.top()), st.pop();
        // reverse(ans.begin(), ans.end());

        // since st was vector return it as it is
        return st;
    }
};

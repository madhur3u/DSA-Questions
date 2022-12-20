class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        stack<int> st;                  // set for bfs
        unordered_set<int> visited;     // this tell us if the room is visited or not
        st.push(0);                     // since room 0 is unlocked, push 0 in stack

        // bfs traversal
        while(!st.empty()) {

            int node = st.top(); st.pop();      // extract node
            visited.insert(node);               // insert in visited set

            for(auto& i : rooms[node]) {        // all connected rooms to node 
                if (!visited.count(i))          // if room i not visited before
                    st.push(i);                 // push in stack
            } 
        }
        // when we out of loop if visited set length == room length means we have visited all rooms
        // else we have not
        return visited.size() == rooms.size();
    }
};

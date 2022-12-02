// https://www.youtube.com/watch?v=FMwpt_aQOGw
// DSU CLASS STARTS
class DSU {
    vector<int> size, parent;
    public:
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if (parent[node] == node) return node;              
        return parent[node] = findParent(parent[node]);     
    }
    void Union(int u, int v) {  // by size

        int pu = findParent(u);       
        int pv = findParent(v);

        if (pu == pv) return;           

        if (size[pu] > size[pv]) {     
            parent[pv] = pu;
            size[pu] += size[pv];     
        }
        else {                        
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};  
// DSU CLASS ENDS
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        
        int n = acc.size();         
        DSU ds(n);                  // make DSU of size n for all people in accounts list
        map<string, int> mapMail;   // either make ordered map at strat or sort list afterwards same time

        /*
        push mail - index pair in map
        if a mail is already present in map means people same so connect both people
        */
        for (int i = 0; i < n; i++) {                       // iterate in account list
            for (int j = 1; j < acc[i].size(); j++) {       // iterate in each person mail starting from 1
                
                string mail = acc[i][j];                    // extract mail

                // if mail not in map means new mail add mail - idx pair 
                if (mapMail.find(mail) == mapMail.end()) 
                    mapMail[mail] = i;
                // else if mail was already present means ith person is same as the preson 
                // whose index stored with mail previously -> mapMail[mail]
                // connect both in DS
                else {
                    ds.Union(i, mapMail[mail]);
                }
            }
        }
        // merge all mails now to parents of each node
        vector<vector<string>> merge(n);

        // extract mail - node pair from map
        // find parent of the node, push mail at nodes's index
        // all connected people mail list will be in merge in sorted order
        for(auto& [mail, node] : mapMail) {
            node = ds.findParent(node);
            merge[node].push_back(mail);
        }
        // final ans formation
        vector<vector<string>> ans;

        // iterate in merged list
        for (int i = 0; i < n; i++) {
            if (merge[i].size() == 0) continue;     // if no mail stored in ith pos cotinue

            // make temp to store list as needed
            vector<string>temp;
            // store the name first, get it using the accounts list
            temp.push_back(acc[i][0]);
            // now insert whole vector elements in temp
            temp.insert(temp.end(), merge[i].begin(), merge[i].end());

            ans.push_back(temp);    // push this vector in ans
        }
        return ans;
    }
};

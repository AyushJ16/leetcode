class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>> adj;
        for(auto &it:tickets){
            adj[it[0]].insert(it[1]);
        }
        stack<string> st;
        st.push("JFK");
        vector <string> ans;
        while(!st.empty()){
            string temp=st.top();
            if(adj[temp].size()==0){
                ans.push_back(temp);
                st.pop();
            }
            else{
                auto it=adj[temp].begin();
                // ans.push_back(*it);
                st.push(*it);
                adj[temp].erase(it);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
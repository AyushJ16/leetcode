class Solution {
public:
    string removeDuplicateLetters(string s) {
        // memset(dp,"$",sizeof dp);
        // int freq[26];
        unordered_map<char,int>lo;
        unordered_set<char>seen;
        int i=0;
        for(auto &c:s){
            // freq[c-'a']++;
            lo[c]=i;
            i++;
        }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(seen.find(c)==seen.end()){
                while(!st.empty() && c<st.top() && i<lo[st.top()]){
                    seen.erase(st.top());
                    st.pop();
                }
                seen.insert(c);
                st.push(c);
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
        // return solve(0,s);

    }
};
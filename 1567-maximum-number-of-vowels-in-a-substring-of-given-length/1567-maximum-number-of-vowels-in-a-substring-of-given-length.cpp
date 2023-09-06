class Solution {
public:
    int maxVowels(string s, int k) {
        deque<int>dq;
        int ans=0;
        unordered_set<char>v;
        v.insert('a');
        v.insert('e');
        v.insert('i');
        v.insert('o');
        v.insert('u');
        for(int i=0;i<k;i++){
            if(v.find(s[i])!=v.end()){
                dq.push_back(i);
            }
            ans=max(ans,(int)dq.size());
        }
        for(int i=k;i<s.size();i++){
            if(v.find(s[i])!=v.end()){
                dq.push_back(i);
            }
            // cout<<i<<" "<<dq.front()<<endl;
            while(!dq.empty() && (i-dq.front())>=k){
                // cout<<'kton';
                dq.pop_front();
            }
            // cout<<dq.size()<<endl;
            ans=max(ans,(int)dq.size());
        }
        return ans;
    }
};
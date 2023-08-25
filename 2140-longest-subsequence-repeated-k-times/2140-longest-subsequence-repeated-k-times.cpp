class Solution {
private:
    bool valid(string &temp,int k,string &s){
        int i=0;
        int n=s.size();
        int m=temp.size();
        int count=0;
        int pos=0;
        while(i<n){
            if(s[i]==temp[pos]){
                pos++;
            }
            i++;
            if(pos==m){
                count++;
                pos=0;
            }
        }
        return count>=k;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans="";
        queue<string> q;
        q.push("");
        while(!q.empty()){
            auto curr=q.front();
            // string temp=curr;
            q.pop();
            for(int i=0;i<26;i++){
                string temp=curr+(char)('a'+i);
                if(valid(temp,k,s)){
                    q.push(temp);
                    ans=temp;
                }
                temp.pop_back();
            }

        }
        return ans;
    }
};
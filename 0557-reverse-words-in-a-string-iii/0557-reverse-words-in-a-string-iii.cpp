class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stringstream ss(s);
        if(s.size()==0){
            return "";
        }
        string sub;
        getline(ss,sub,' ');
        reverse(sub.begin(),sub.end());
        ans+=sub;
        while(ss.good()){
            getline(ss,sub,' ');
            ans+=' ';
            reverse(sub.begin(),sub.end());
            ans+=sub;
        }
        return ans;
    }
};
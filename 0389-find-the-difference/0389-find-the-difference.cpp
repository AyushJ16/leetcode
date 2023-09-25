class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.length()==0){
            return t[0];
        }
        vector<int>cf(26,0);
        for(char &c:s){
            cf[c-'a']++;
        }
        // char ans;
        for(char &c:t){
            cf[c-'a']--;
            if(cf[c-'a']<0){
                return c;
            }
        }
        return ' ';

    }
};
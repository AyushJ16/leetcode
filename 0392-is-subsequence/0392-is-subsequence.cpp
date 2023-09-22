class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s==""){
            return true;
        }
        int n=s.size(),m=t.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
            if(i==n){
                return true;
            }
            if(j==m){
                return false;
            }
            
        }
        return false;
    }
};
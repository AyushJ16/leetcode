class Solution {
private:
    int getVariance(int i,int j,string &s,vector<int>&count){
        char ma=(char)('a'+i),mi=(char)('a'+j);
        int left=count[j];
        int var=0;
        int t=0;
        int mac=0;int mic=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==ma){
                t++;
                mac++;
            }
            if(s[i]==mi){
                t--;
                left--;
                mic++;
            }
            if(mic>0)
            var=max(t,var);
            if(t<0 && left>0){
                t=0;
                mac=0;
                mic=0;
            }

        }

        return var;
    }
public:
    int largestVariance(string s) {
        vector<int> count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(count[i]!=0 && count[j]!=0 && i!=j){
                    ans=max(ans,getVariance(i,j,s,count));
                }
            }
        }
        return ans;
    }
};
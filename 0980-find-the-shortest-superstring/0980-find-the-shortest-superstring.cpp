class Solution {
    vector<vector<string>>dp;
    string M(string &a,string &b){
        int n=a.size(),m=b.size(),len=1,idx=0;
        while(len<=min(n,m)){
            if(a.substr(n-len)==b.substr(0,len)){
                idx=len;
            }
            len++;
        }
        return b.substr(idx);
    }
private:
    string solve(int source,int mask,vector<string>&words,vector<vector<string>>&merge,int n){
        if(dp[source][mask]!=""){
            return dp[source][mask];
        }
        int mini=INT_MAX;
        if(mask==((1<<n)-1)){
            return "";
        }
        string res="";
        for(int i=0;i<n;i++){
            if(mask & (1<<i))continue;
            string temp=merge[source][i]+solve(i,mask|(1<<i),words,merge,n);
            if(temp.size()<mini){
                res=temp;
                mini=temp.size();
            }
        }
        return dp[source][mask]=res;
    }
public:
    string shortestSuperstring(vector<string>& words) {
        int n=words.size();
        int all=1<<(n+1);
        all--;
        dp.resize(n,vector<string>(all+1,""));
        vector<vector<string>>merge(n,vector<string>(n,""));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                merge[i][j]=M(words[i],words[j]);
            }
        }
        string ans="";
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            string temp=words[i]+solve(i,0|(1<<i),words,merge,n);
            if(temp.length()<mini){
                ans=temp;
                mini=temp.length();
            }
        }
        return ans;

    }
};
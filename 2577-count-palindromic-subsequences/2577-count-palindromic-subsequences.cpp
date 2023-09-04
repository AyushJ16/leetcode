#define mod 1000000007
#define ll long long
class Solution {
        ll dp[10001][11][11][6];
private:
    int solve(string &s,int i,int o, int t,int c){
        if(c==5)return 1;
        if(i>=s.size())return 0;
        if(dp[i][o+1][t+1][c]!=-1){
            return dp[i][o+1][t+1][c];
        }
        int np=solve(s,i+1,o,t,c);
        int p=0;
        if(c==0){
            p+=solve(s,i+1,s[i]-'0',t,c+1);
        }
        else if(c==1){
            p+=solve(s,i+1,o,s[i]-'0',c+1);
        }
        else if(c==2){
            p+=solve(s,i+1,o,t,c+1);
            
        }
        else if(c==3){
            if(s[i]-'0'==t){
                p+=solve(s,i+1,o,t,c+1);
            }
        }
        else{
            if(s[i]-'0'==o){
                p+=solve(s,i+1,o,t,c+1);
            }
            
        }
        return dp[i][o+1][t+1][c]=(p+np)%mod;

    }
public:
    int countPalindromes(string s) {
        int n=s.size();
        //number of palindrome substrings
        // vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(j==i)dp[i][j]=1;
        //         else if(j==(i+1))
        //         if(s[i]==s[j])dp[i][j]=3;
        //         else dp[i][j]=2;
        //     }
        // }
        // for(int g=2;g<n;g++){
        //     for(int i=0,j=g;j<n;i++,j++){
        //         if(s[i]==s[j])dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
        //         else dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
        //     }
        // }
        // return dp[0][n-1];
        memset(dp,-1,sizeof(dp));
        return solve(s,0,-1,-1,0)%mod;
    }
};
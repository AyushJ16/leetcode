class Solution {
int dp[100001][2];
private:
    bool solve(int n,int i){
        if(n==0){
            return false;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        bool ans=false;
        for(int j=1;j*j<=n;j++){
            // if(i==0){
                if(solve(n-(j*j),!i)==0)
                return dp[n][i]=1;
            // }
        }
        return dp[n][i]=0;
    }
public:
    bool winnerSquareGame(int n) {
        if(n==1){
            return true;
        }
        // if(n==2){
        //     return false;
        // }
        int a=sqrt(n);
        if(a*a == n){
            return true;
        }
        memset(dp,-1,sizeof dp);
        return solve(n,0);
    }
};
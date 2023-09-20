class Solution {
int dp[100001];
private:
    bool solve(int n){
        if(n==0){
            return false;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        bool ans=false;
        for(int j=1;j*j<=n;j++){
            if(solve(n-(j*j))==0)return dp[n]=1;
        }
        return dp[n]=0;
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
        return solve(n);
    }
};
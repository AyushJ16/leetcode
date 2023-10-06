class Solution {
int dp[59];
private:    
    int solve(int n){
        if(n==1){
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        int ans=INT_MIN;
        for(int i=1;i<=(n/2);i++){
            ans=max(ans,solve(i)*solve(n-i));
        }
        if(ans<n){
            ans= n;
        }
        return dp[n]=ans;
    }
public:
    int integerBreak(int n) {
        memset(dp,-1,sizeof dp);
        int ans=INT_MIN;
        for(int i=1;i<=(n/2);i++){
            ans=max(ans,solve(i)*solve(n-i));
        }
        return ans;
    }
};
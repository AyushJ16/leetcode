class Solution {
int mod=1e9+7;
private:
    int solve(int n,int m,int k,int prev,vector<vector<vector<int>>> &dp){
        if(n==0){
            if(k==0){
                return 1;
            }
            return 0;
        }
        if(dp[n][k][prev]!=-1)return dp[n][k][prev];
        int ans=0;
        for(int j=1; j<=m; j++)
        {
            if(k > 0 && j> prev) ans = ( ans + solve(n-1, m, k-1, j, dp)) % mod; 
            else if(j<= prev) ans = ( ans + solve(n-1, m, k, prev, dp)) % mod;
        }
        return dp[n][k][prev]=ans%mod;
    }
public:
    int numOfArrays(int n, int m, int k) {
        // memset(dp,-1,sizeof dp);
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (k+1, vector<int> (m+1, -1)));
        if(k>m)return 0;
        return solve(n,m,k,0,dp)%mod;
    }
};
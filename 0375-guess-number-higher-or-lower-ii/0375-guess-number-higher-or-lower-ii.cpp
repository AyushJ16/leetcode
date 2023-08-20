class Solution {
public:
    int solve(vector<vector<int>>& dp, int l, int r) {
        if(l >= r){return 0;}
        if(dp[l][r] != -1){return dp[l][r];}
        int ans = INT_MAX;
        for(int i=l; i<=r; i++){
            ans = min(ans, i + max(solve(dp, l, i-1), solve(dp, i+1, r)));
        }
        return dp[l][r] = ans;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solve(dp, 1, n);
        return ans;
    }
};
class Solution {
public:
    const long long mod = 1e9 + 7;
    int n;
    vector<vector<int>> dp;
    int f(int i, int j) {
        if (i == n) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        long long ans = 0;

        switch (j) {
            case 0: ans=(ans + f(i+1, 1)) % mod;
                break; 
            case 1: ans=(ans + f(i+1, 0) + f(i+1, 2)) % mod;
                break;
            case 2: ans=(ans+f(i+1,0)+f(i+1,1)+f(i+1,3)+f(i+1,4))%mod;
                break;
            case 3: ans = (ans+f(i+1,2) + f(i+1,4)) % mod;
                break;
            case 4: ans = (ans+f(i+1, 0)) % mod;
                break;
        }
        return dp[i][j] = ans;
    }
    int countVowelPermutation(int n) {
        this->n = n;
        dp.assign(n + 1, vector<int>(5, -1));
        long long ans = 0;
        for (int j = 0; j < 5; j++)
            ans = (ans + f(1,j)) % mod;
        return ans;
    }
};
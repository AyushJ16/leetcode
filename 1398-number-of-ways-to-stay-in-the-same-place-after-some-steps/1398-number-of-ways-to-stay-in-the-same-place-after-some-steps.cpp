class Solution {
vector<vector<long long> > dp;
long long mod=1e9+7;
private:
    long long solve(int i,int j,int arrlen){
        if(j==0){
            return (i==0)?1:0;
        }
        if(i>=arrlen || i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long ways=0;
        ways+=solve(i,j-1,arrlen)%mod;
        ways+=solve(i-1,j-1,arrlen)%mod;
        ways+=solve(i+1,j-1,arrlen)%mod;
        return dp[i][j]=ways%mod;
    }
public:
    int numWays(int steps, int arrLen) {
        dp.resize(min(arrLen,steps),vector<long long>(steps+1,-1));
        return solve(0,steps,arrLen)%mod;
    }
};
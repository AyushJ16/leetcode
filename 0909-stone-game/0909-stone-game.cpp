class Solution {
    int dp[1000][1000];
private:
    int memo(int i,int j,vector<int>&piles){
        if(i==j){
            return piles[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int r=piles[i]-memo(i+1,j,piles);
        int l=piles[j]-memo(i,j-1,piles);
        return dp[i][j]=max(r,l);
    }
public:
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        int n=piles.size();

        return memo(0,n-1,piles)>0;
        return 1;
    }
};
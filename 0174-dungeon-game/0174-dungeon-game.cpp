class Solution {
    vector<vector<int>>dp;
    int solve(int i,int j,int n,int m,vector<vector<int>>&dungeon){
        if(i==n-1 && j==m-1){
            if(dungeon[i][j]>0){
                return 1;
            }
            else{
                return 1-dungeon[i][j];
            }
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int d=1e9,r=1e9;
        if(i+1 <= n-1)
        d=solve(i+1,j,n,m,dungeon);
        if(j+1 <=m-1)
        r=solve(i,j+1,n,m,dungeon);
        int ans=min(r,d)-dungeon[i][j];
        if(ans>0){
            return dp[i][j]=ans;
        }
        else{
            return dp[i][j]=1;
        }
        

    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        dp.resize(n,vector<int>(m,-1));
        // N=n;M=m;
        int ans=solve(0,0,n,m,dungeon);
        return ans;
        
    }
};
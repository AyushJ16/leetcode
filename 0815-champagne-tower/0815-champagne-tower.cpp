class Solution {
double dp[101][101];
private:    
    double solve(int i ,int j, int p){
        if(i<0 || j>i || j<0){
            return 0.00;
        }
        if(i==0 && j==0){
            return p;
        }
        if(dp[i][j]>-1){
            return dp[i][j];
        }
        double left,right;
        left=max(0.0,(solve(i-1,j-1,p)-1)/2);
        right=max(0.0,(solve(i-1,j,p)-1)/2);
        return dp[i][j]=left+right;
        

    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(dp,-1,sizeof dp);
        return min(1.00,solve(query_row,query_glass,poured));
    }
};
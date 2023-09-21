class Solution {
    int pre[1002];
    int dp[1001][1001];
private:
    int solve(int i,int j,vector<int>&stones){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // if(c==0){
            return dp[i][j]=max((pre[j]-pre[i])-solve(i,j-1,stones),(pre[j+1]-pre[i+1])-solve(i+1,j,stones));
        
        // else{
        //     return dp[i][j][c]=max(pre[j]-pre[i]-solve(i,j-1,!c,stones),pre[j+1]-pre[i+1]-solve(i+1,j,!c,stones));

        
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        pre[0]=0;
        // pre[1]=stones[1];
        for(int i=0;i<n;i++){
            pre[i+1]=stones[i]+pre[i];
        }
        memset(dp,-1,sizeof dp);
        return solve(0,n-1,stones);

    }
};
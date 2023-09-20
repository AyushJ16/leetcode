class Solution {
int dp[501][501];
int pre[502];
private:
    int solve(int i,int j){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int score=INT_MIN;
        for(int k=i;k<j;k++){
            if((pre[k+1]-pre[i])>(pre[j+1]-pre[k+1])){
                score=max(score,pre[j+1]-pre[k+1]+solve(k+1,j));
            }
            else if((pre[k+1]-pre[i])<(pre[j+1]-pre[k+1])){
                score=max(score,(pre[k+1]-pre[i])+solve(i,k));
            }
            else{
                score=max(score,pre[j+1]-pre[k+1]+solve(k+1,j));
                score=max(score,(pre[k+1]-pre[i])+solve(i,k));

            }
        }
        return dp[i][j]=score;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        memset(dp,-1,sizeof dp);
        pre[0]=0;
        pre[1]=stoneValue[0];
        for(int i=1;i<stoneValue.size();i++){
            pre[i+1]=stoneValue[i]+pre[i];
        }
        return solve(0,stoneValue.size()-1);
    }   
};
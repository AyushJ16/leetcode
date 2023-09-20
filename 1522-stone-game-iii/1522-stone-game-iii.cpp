class Solution {
    int dp[50001];
private:    
    int solve(int i,vector<int>&stoneValue){
        if(i==stoneValue.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MIN;
        int sum=0;
        for(int k=i;k<=(min((int)stoneValue.size()-1,(i-1)+3));k++){
            sum+=stoneValue[k];
            ans=max(ans,sum-solve(k+1,stoneValue));
        }
        return dp[i]=ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof dp);
        int ans=solve(0,stoneValue);
        int sum=0;
        for(int &i:stoneValue){
            sum+=i;
        }
        if(ans==0){
            return "Tie";
        }
        if(ans>0){
            return "Alice";
        }
        return "Bob";
    }
};
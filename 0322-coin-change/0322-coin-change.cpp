class Solution {
    vector<vector<int>>dp;
private:
    int memo(int i,int t,vector<int>&coins){
        if(t==0){
            return 0;
        }
        if(i==coins.size()){
            if(t!=0){
                return 10001 ;
            }
            else{
                return 0;
            }
        }
        if(dp[i][t]!=0){
            return dp[i][t];
        }
        int ways=10001;
        if(t>=coins[i]){
            ways=min(ways,1+memo(i,t-coins[i],coins));
        }
        ways=min(ways,memo(i+1,t,coins));
        return dp[i][t]=ways;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize(n,vector<int>(amount+1,0));
        if(amount==0){
            return 0;
        }
        return memo(0,amount,coins)==10001?-1:dp[0][amount];
    }
};
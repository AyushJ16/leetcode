#define ll long long

class Solution {
    vector<ll>dp;
    int mod=1e9+7;
private:
    ll memo(int i,int low,int high, int zero,int one){
        if(i>high){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(i>=low){
            dp[i]=1;
        }
        else{
            dp[i]=0;
        }
        dp[i]+=memo(i+zero,low,high,zero,one)+memo(i+one,low,high,zero,one);
        return dp[i]%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+1,-1);
        return memo(0,low,high,zero ,one);
    }
};
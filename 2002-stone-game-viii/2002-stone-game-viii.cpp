class Solution {
    int dp[100001];
    int pre[100001];
private:
    int solve(int i,int n){
        if(i==n-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MIN;
        for(int k=max(i+1,n-2);k<n;k++){
            ans=max(ans,pre[k+1]-solve(k,n));
        }
        return dp[i]=ans;
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        pre[0]=0;
        int n=stones.size();
        for(int i=0;i<n;i++){
            pre[i+1]=stones[i]+pre[i];
        }
        memset(dp,0,sizeof dp);
        dp[n-1]=pre[n];
        for(int i=n-2;i>=1;i--){
            dp[i]=max(dp[i+1],pre[i+1]-dp[i+1]);
        }
        // return solve(0,n);
        return dp[1];
    }
};
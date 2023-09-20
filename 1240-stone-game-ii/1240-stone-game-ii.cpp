class Solution {
int dp[101][10001];
private:
    int solve(int i,int M,vector<int>&piles){
        if(i==piles.size()){
            return 0;
        }
        if(dp[i][M]!=-1){
            return dp[i][M];
        }
        int ans=INT_MIN;
        int sum=0;
        int maxi=M;
        int tot=0;
        for(int k=i;k<=min((int)piles.size()-1,(i-1)+2*M);k++){
            tot++;
            maxi=max(maxi,tot);
            sum+=piles[k];
            // cout<<i<<" "<<sum<<" "<<maxi<<endl;
            ans=max(ans,sum-solve(k+1,maxi,piles));
            // cout<<i<<" "<<ans<<endl;
        }
        return dp[i][M]=ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(int &i:piles){
            sum+=i;
        }
        int ans=solve(0,1,piles);
        cout<<ans<<" ";
        int a=(sum-ans)/2;
        cout<<a;
        return a+ans;
    }
};
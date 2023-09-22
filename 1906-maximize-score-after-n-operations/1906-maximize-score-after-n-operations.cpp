class Solution {
    int dp[1<<14];
private:    
    int solve(int i,int n,int mask,vector<int>&nums){
        if(mask==(1<<(2*n))-1){
            return 0;
        }
        if(dp[mask]!=-1){
            return dp[mask];
        }
        int score=0;int a,b;
        for(int j=0;j<nums.size();j++){
            if((mask&(1<<j))){
                continue;
            }
            a=nums[j];
            for(int k=j+1;k<nums.size();k++){
                if((mask&(1<<k)))continue;
                b=nums[k];
                score=max(score,i*gcd(a,b)+solve(i+1,n,(mask|(1<<j))|(1<<k),nums));
            }
        }
        return dp[mask]=score;
    }
public:
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        int n=nums.size();
        n/=2;
        return solve(1,n,0,nums);
    }
};
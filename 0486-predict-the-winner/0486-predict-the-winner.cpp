class Solution {
vector <vector<int> >dp;
int memo(int i,int j,vector<int>&nums){
    if(i==j){
        return nums[i];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int l=nums[i]-memo(i+1,j,nums);
    int r=nums[j]-memo(i,j-1,nums);
    return dp[i][j]=max(l,r);
}
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n,-1));
        return memo(0,n-1,nums)>=0;
    }
};
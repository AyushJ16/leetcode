class Solution {
    vector<int>dp;
private:
    int memo(int t,vector<int>&nums){
        if(t==0){
            return 1;
        }
        if(t<0){
            return 0;
        }
        if(dp[t]!=-1){
            return dp[t];
        }
        int ways=0;
        for(auto &num:nums){
            ways+=memo(t-num,nums);
        }
        return dp[t]=ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,-1);
        return memo(target,nums);
    }
};
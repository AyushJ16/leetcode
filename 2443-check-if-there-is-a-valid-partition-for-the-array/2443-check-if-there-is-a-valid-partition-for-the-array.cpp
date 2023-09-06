class Solution {
    vector<int>dp;
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            int id=i+1;
            if(i>0 && nums[i]==nums[i-1]){
                dp[id]|=dp[id-2];
            }
            if (i > 1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2]){
                dp[id]|=dp[id-3];
            }
            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2) {
                dp[id]=dp[id-3];
            }

        }
        return dp[n];
    }
};
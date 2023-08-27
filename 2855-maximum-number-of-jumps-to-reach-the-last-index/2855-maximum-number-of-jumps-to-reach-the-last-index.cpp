class Solution {
public:
    int helper(vector<int>& nums, int target,int index,vector<int>&dp){
        if(index==nums.size()-1) return 0;
        int maxi=-1;
        if(dp[index]!=0) return dp[index];
        for(int i=index+1;i<nums.size();i++){
            if(abs(nums[index]-nums[i])<=target){
                    int t=helper(nums,target,i,dp);
                    if(t!=-1)
                    maxi=max(maxi,1+t);
            }
        }
        return dp[index]=maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),0);
        int ans=helper(nums,target,0,dp);
        return ans<=0?-1:ans;
    }
};
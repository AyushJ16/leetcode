class Solution {
public:
    int count(vector<int>&nums1, vector<int>&nums2, int i, int j, vector<vector<int>>&dp){
        if(i==nums1.size() || j==nums2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=0;
        if(nums1[i]==nums2[j]){
            res=1+count(nums1, nums2, i+1, j+1, dp);
        }
        else{
            res=max(count(nums1, nums2, i+1, j, dp), count(nums1, nums2, i, j+1, dp));
        }
        return dp[i][j]=res;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return count(nums1, nums2, 0, 0, dp);
    }
};
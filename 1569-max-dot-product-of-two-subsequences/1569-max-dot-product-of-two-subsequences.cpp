class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return INT_MIN;

        if(dp[i][j]!=-1)return dp[i][j];    
        
        int bothP = nums1[i] * nums2[j] + max(0, solve(i - 1, j - 1, nums1, nums2, dp));
        int altP = solve(i - 1, j, nums1, nums2,dp);
        int altPq = solve(i, j - 1, nums1, nums2,dp);

        return dp[i][j] = max(bothP, max(altP, altPq));
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n, vector<int>(m,-1));        
        int ans = solve(n - 1, m - 1, nums1, nums2,dp);
        return ans;     
    }
};
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>dp(n+1, 0);
        for(int i=0;i<=n;i++){
            dp[i]=0;
        }
        for(int i=m-1;i>=0;i--){
            int prev=0;
            for(int j=n-1;j>=0;j--){
                int curr=dp[j];
                if(nums1[i]==nums2[j]){
                    dp[j]=1+prev;
                }
                else{
                    dp[j]=max(dp[j], dp[j+1]);
                }
                prev=curr;
            }
        }
        return dp[0];
    }
};
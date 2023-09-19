class Solution {
vector<vector<int>>dp;
private:
    int solve(int i,int swap,vector<int>& nums1,vector<int>& nums2,const int n){
        if(i==n){
            return 0;
        }
        if(dp[i][swap]!=-1){
            return dp[i][swap];
        }
        int s=100000,ns=100000;
        if(i==0){
            ns=0+solve(i+1,0,nums1,nums2,n);
            s=1+solve(i+1,1,nums1,nums2,n);
        }
        else if(nums1[i]==nums2[i]){
            ns=0+solve(i+1,0,nums1,nums2,n);
        }
        else{
            if((nums1[i-1]>=nums1[i]||nums2[i-1]>nums2[i])&&(nums1[i-1]>=nums2[i]||nums2[i-1]>=nums1[i])){
                return 100000;
            }
            if(swap){
                if(nums1[i-1]<nums1[i] && nums2[i-1]<nums2[i] && nums1[i-1]<nums2[i] && nums2[i-1]<nums1[i]){
                    ns= 0+solve(i+1,0,nums1,nums2,n);
                    s=1+solve(i+1,1,nums1,nums2,n);
                }
                else if(nums1[i-1]>=nums2[i] || nums2[i-1]>=nums1[i]){
                    s=1+solve(i+1,1,nums1,nums2,n);
                }
                else{
                    ns=0+solve(i+1,0,nums1,nums2,n);
                }


            }
            if(!swap){
                if(nums1[i-1]<nums1[i] && nums2[i-1]<nums2[i] && nums1[i-1]<nums2[i] && nums2[i-1]<nums1[i]){
                    ns= 0+solve(i+1,0,nums1,nums2,n);
                    s=1+solve(i+1,1,nums1,nums2,n);

                }
                else if(nums2[i-1]>=nums2[i] || nums1[i-1]>=nums1[i]){
                    s=1+solve(i+1,1,nums1,nums2,n);
                }
                else{
                    ns=0+solve(i+1,0,nums1,nums2,n);
                }

            }
        }
        return dp[i][swap]=min(s,ns);
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        dp.assign(nums1.size(),vector<int>(2,-1));
        // cout<<dp[0];
        int n=nums1.size();
        return solve(0,0,nums1,nums2,n);
        return 0;

    }
};
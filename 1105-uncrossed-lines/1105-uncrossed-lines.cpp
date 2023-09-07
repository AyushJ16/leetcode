class Solution {
    unordered_map<int,vector<int>>mp;
    vector<vector<int>>dp;
private:
    int memo(int i,int j ,vector<int>&nums1){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ti=-1;
        for(int k=0;k<mp[nums1[i]].size();k++){
            if(mp[nums1[i]][k]>j)
            break;
            ti=mp[nums1[i]][k];
        }
        int t=0,nt=0;
        nt=0+memo(i-1,j,nums1);
        if(ti!=-1)
        t=1+memo(i-1,ti-1,nums1);
        return dp[i][j]=max(t,nt);

    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        for(int i=0;i<n;i++){
            mp[nums2[i]].push_back(i);
        
        }
        int n1=nums1.size();
        dp.resize(n1,vector<int>(n,-1));
        return memo(n1-1,n-1,nums1);

    }
};
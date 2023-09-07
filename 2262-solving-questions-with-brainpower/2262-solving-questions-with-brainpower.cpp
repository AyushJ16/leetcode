class Solution {
vector<long long>dp;
private:
    long long memo(int i,vector<vector<int>>& questions,int n){
        if(i>(n-1)){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long s=0,ns=0;
        ns=0+memo(i+1,questions,n);
        s=questions[i][0]+memo(i+questions[i][1]+1,questions,n);
        return dp[i]=max(s,ns);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        dp.resize(n,-1);
        return memo(0,questions,n);
    }
};
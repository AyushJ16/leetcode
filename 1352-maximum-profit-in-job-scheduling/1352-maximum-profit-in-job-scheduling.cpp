class Solution {
private:
    int solve(int i,int e,vector<tuple<int,int,int> > &job,vector<int>&dp){
        if(i>=job.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if((get<0>(job[i]))<e){
            return dp[i]=solve(i+1,e,job,dp);
        }
        int t=0;
        int k;
        t=max(t,solve(i+1,e,job,dp));
        for(k=i+1;k<job.size();k++){
            if(get<0>(job[k])>=get<1>(job[i])){
                break;
            }
        }
        t=max(t,get<2>(job[i])+solve(k,get<1>(job[i]),job,dp));
        return dp[i]=t;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int,int,int> > job(startTime.size());
        for(int i=0;i<startTime.size();i++){
            job[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(job.begin(),job.end());
        vector<int> dp(startTime.size(),-1);
        return solve(0,0,job,dp);
    }
};
class Solution {
    int dp[501][501];
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n,cost,time);
    }

    int f(int i, int walls, vector<int>& cost, vector<int>& time) {
        if(walls <= 0) return 0;

        if(i>=cost.size()) return 1e9;

        if(dp[i][walls]!=-1) return dp[i][walls];

        int not_pick = f(i+1,walls,cost,time);
        int pick = cost[i] + f(i+1,walls-time[i]-1,cost,time);
        return dp[i][walls] = min(pick,not_pick);
    }
};
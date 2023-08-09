class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        // vector <vector<int> > dp(n+1,vector<int>(m+1,1e5));
        vector <int> prev(m+1,1e5);

        for(int i=1;i<=n;i++){
            vector <int> curr(m+1,1e5);
            for(int j=1;j<=m;j++){
                if(i==1 & j==1){
                    curr[j]=grid[i-1][j-1];
                    continue;
                }
                curr[j]=min(grid[i-1][j-1]+prev[j],grid[i-1][j-1]+curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
};
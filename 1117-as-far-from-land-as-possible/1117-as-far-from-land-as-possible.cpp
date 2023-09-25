class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>>q;
        int n=grid.size();
        vector<vector<int>>dis(n,vector<int>(n,1e5));
        int d=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({0,i,j});
                    dis[i][j]=0;
                }
            }
        }
        if(q.size()==(n*n)|| q.size()==0){
            return -1;
        }
        vector<int>dx={-1,0,1,0},dy={0,-1,0,1};
        int ans=0;
        while(!q.empty()){
            auto[cd,cr,cc]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=cr+dx[i];
                int nc=cc+dy[i];
                if(min(nr,nc)>=0 && max(nr,nc)<n){
                    if(dis[nr][nc]==1e5 || dis[nr][nc]>cd+1){
                        q.push({cd+1,nr,nc});
                        dis[nr][nc]=cd+1;
                    }
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dis[i][j]);
            }
        }
        return ans;

    }
};
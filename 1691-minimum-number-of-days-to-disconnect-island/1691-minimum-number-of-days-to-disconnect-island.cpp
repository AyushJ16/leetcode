class Solution {
    int timer;
    int ans=0;
private:    
    void dfs(int i,int j,int pi,int pj,vector <vector<int>> &low,vector <vector<int>> &tin,vector <vector<bool>> &vis,vector<vector<int>>& grid){
        low[i][j]=timer;
        tin[i][j]=timer;
        vis[i][j]=true;
        timer++;
        int child=0;
        vector<int>dx={-1,0,1,0},dy={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(nr==pi && nc==pj){
                continue;
            }
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size()){
                if(!vis[nr][nc] && grid[nr][nc]){
                    dfs(nr,nc,i,j,low,tin,vis,grid);
                    low[i][j]=min(low[i][j],low[nr][nc]);
                    if(low[nr][nc]>=tin[i][j] && pi!=-1){
                        ans++;
                    }
                    child++;
                }
                else if(grid[nr][nc]){
                    low[i][j]=min(low[i][j],tin[nr][nc]);
                }
            }


        }
        if(child>1 && pi==-1 && pj==-1){
            ans++;
        }
        
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();int m=grid[0].size();
        int ones=0;
        vector <vector<int>> low(n,vector<int>(m,INT_MAX));
        vector <vector<int>> tin(n,vector<int>(m,INT_MAX));
        vector <vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    ones++;
                }
                if(grid[i][j] && !vis[i][j]){
                    cnt++;
                    if(cnt>1){
                        return 0;
                    }
                    timer=1;
                    dfs(i,j,-1,-1,low,tin,vis,grid);
                }
            }
        }
        if(cnt==0){
            return 0;
        }
        else if(ans>0){
            return 1;
        }
        else if(ones==1){
            return 1;
        }
        else return 2;

    }
};
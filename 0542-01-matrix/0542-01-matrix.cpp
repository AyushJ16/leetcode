class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector <vector<int>>dis(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({i,j,0});
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
            while(!q.empty()){
                vector<int> dx={-1,0,1,0},dy={0,-1,0,1};
                // while(!q.empty()){
                    auto p=q.front();
                    int row=get<0>(p);
                    int col=get<1>(p);
                    int steps=get<2>(p);
                    dis[row][col]=steps;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nr=row+dx[k];
                        int nc=col+dy[k];
                        if(nr<n && nc<m && nr>=0 && nc>=0 && vis[nr][nc]==0 && mat[nr][nc]==1){
                            vis[nr][nc]=1;
                            q.push({nr,nc,steps+1});
                        }
                    }
                // }

            }
        // }
        return dis;
    }
};
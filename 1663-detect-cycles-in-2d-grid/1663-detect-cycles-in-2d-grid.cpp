class Solution {
vector<int>vis;
unordered_map<int,int>pathvis;
vector<int>dx={-1,0,1,0},dy={0,-1,0,1};
private:
    bool dfs(int i,int j,int pi,int pj,char c,vector<vector<char>>& grid){
        vis[(i*grid[0].size()+j)]=1;
        pathvis[(i*grid[0].size()+j)]=1;
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(min(nr,nc)>=0&& nr<grid.size() && nc<grid[0].size() ){
                if(grid[nr][nc]==c){
                    if(nr==pi && nc==pj)continue;
                
                    if(pathvis[(nr*grid[0].size()+nc)]==1){
                        return true;
                    }
                    else{
                        if(dfs(nr,nc,i,j,c,grid)){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vis.resize(m*n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[(i*m+j)]==0){
                    // pathvis.resize(m*n,0);
                    pathvis.clear();
                    // cout<<pathvis[0]<<endl;
                    if(dfs(i,j,-1,-1,grid[i][j],grid))
                    return true;
                }
            }
        }
        return false;
    }
};
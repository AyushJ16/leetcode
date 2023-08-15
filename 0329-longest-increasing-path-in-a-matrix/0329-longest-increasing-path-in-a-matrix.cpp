class Solution {
private:
    int dfs(int curr,vector<vector<int>>&adj,vector<int>&vis,vector<int>&dis){
        vis[curr]=1;
        for(auto &it:adj[curr]){
            if(!vis[it]){
                dis[curr]=max(dis[curr],1+dfs(it,adj,vis,dis));
            }
            else{
                dis[curr]=max(dis[curr],1+dis[it]);
            }
        }
        return dis[curr];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector <int> dx={0,-1,0,1},dy={-1,0,1,0};
        vector<vector <int> > adj(n*m);
        vector <int> indegree(n*m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    int r=i+dy[k],c=j+dx[k];
                    if(r>=0 && r<m && c>=0 && c<n){
                        if(matrix[r][c]<matrix[i][j]){
                            cout<<i*n+(j)<<' '<<r*n+(c)<<endl;
                            adj[r*n + (c)].push_back(i*n + (j));
                            indegree[i*n+j]++;
                        }
                    }
                }
            }
        }
        int ans=0;
        vector<int> vis(n*m);
        vector<int> dis(m*n,0);
        for(int i=0;i<(n*m);i++){
            if(indegree[i]==0)
            ans=max(ans,1+dfs(i,adj,vis,dis));
        }
        return ans;
    }
};
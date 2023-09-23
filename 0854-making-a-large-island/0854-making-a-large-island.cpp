class DisjointSet{
public:
    vector<int>size;vector<int>parent;
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUParent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findUParent(parent[u]);
    }
    void unionBySize(int u,int v){
        int up_u=findUParent(u);
        int up_v=findUParent(v);
        if(up_u==up_v)return;
        if(size[up_u]>=size[up_v]){
            size[up_u]+=size[up_v];
            parent[up_v]=up_u;
        }
        if(size[up_u]<size[up_v]){
            size[up_v]+=size[up_u];
            parent[up_u]=up_v;
        }
        return;
    }
};
class Solution {

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        vector<int>dx={0,-1,0,1},dy={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                for(int k=0;k<4;k++){
                    int nr=i+dx[k];
                    int nc=j+dy[k];
                    if(min(nr,nc)>=0&& max(nr,nc)<n ){
                        if(grid[nr][nc]==1)
                            ds.unionBySize((i*n+j),(nr*n+nc));
                    }
                }
            }
        }
        int ans=-1;
        unordered_set<int>parents;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int temp=1;
                    for(int k=0;k<4;k++ ){
                        int nr=i+dx[k];
                        int nc=j+dy[k];
                        if(min(nr,nc)>=0&& max(nr,nc)<n ){
                            if(grid[nr][nc]==1){
                                int up=ds.findUParent(nr*n+nc);
                                if(parents.find(up)==parents.end()){
                                    temp+=ds.size[up];
                                    parents.insert(up);
                                }
                            }
                        }
                    }
                    parents.clear();
                    ans=max(ans,temp);
                }
            }
        }
        return ans==-1?n*n:ans;
    }
};
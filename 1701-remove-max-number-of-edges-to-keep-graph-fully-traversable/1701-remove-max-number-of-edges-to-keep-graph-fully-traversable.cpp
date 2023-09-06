class DisjointSet{
public:
    vector<int> parent;vector<int>size;
    int maxsize=1;
    DisjointSet (int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUParent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findUParent(parent[u]);
    }
    void unionBySize(int u,int v){
        int up_u=findUParent(u);
        int up_v=findUParent(v);
        if(up_u==up_v){
            return;
        }
        if(size[up_u]>=size[up_v]){
            size[up_u]+=size[up_v];
            parent[up_v]=up_u;
            maxsize=max(maxsize,size[up_u]);
        }
        else{
            size[up_v]+=size[up_u];
            parent[up_u]=up_v;
            maxsize=max(maxsize,size[up_v]);

        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet Alice(n),Bob(n);
        int ans=0;
        for(auto &edge:edges){
            if(edge[0]==3 && Alice.findUParent(edge[1])!=Alice.findUParent(edge[2])){
                Alice.unionBySize(edge[1],edge[2]);
                Bob.unionBySize(edge[1],edge[2]);
            }
            else if(edge[0]==3){
                ans++;
            }
        }
        for(auto &edge:edges){
            if(edge[0]==1){
                if(Alice.findUParent(edge[1])!=Alice.findUParent(edge[2])){
                    Alice.unionBySize(edge[1],edge[2]);
                }
                else{
                    ans++;
                }
            }
            if(edge[0]==2){
                if(Bob.findUParent(edge[1])!=Bob.findUParent(edge[2])){
                    Bob.unionBySize(edge[1],edge[2]);
                }
                else{
                    ans++;
                }
            }
        }
        if(Alice.maxsize!=n || Bob.maxsize!=n){
            return -1;
        }
        return ans;
    }
};
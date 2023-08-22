class Solution {
    vector<vector<int>> adj;
    vector <bool> vis;
    int target;
private:
    double dfs(int node,int t){
        if(node!=1 && (adj[node].size()==1 || t==0) ){
            return node==target;
        }
        vis[node]=true;
        double res=0.0;
        for(auto next:adj[node]){
            if(!vis[next]){
                res+=dfs(next,t-1);
            }
        }
        if(node!=1)
        return res/(adj[node].size()-1);
        return res/adj[node].size();
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1){
            return 1.0;
        }
        this->target=target;
        adj.resize(n+1,vector<int>());
        for(auto e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis=vector<bool>(n+1,false);
        return dfs(1,t);


    }

};
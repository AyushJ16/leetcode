class Solution {
    vector<int>count;
    vector<int> ans;
    vector<int>sub;
    int N;
private:
    void dfs(int node,int parent,vector<vector<int> >&adj){
        for(auto &child:adj[node]){
            if(child!=parent){
                dfs(child,node,adj);
                count[node]+=count[child];
                sub[node]+=sub[child]+count[child];
            }
        }
    }
    void dfs2(int node,int parent,vector<vector<int>> &adj){
        for(auto &child:adj[node]){
            if(child!=parent)
            {
                ans[child]=ans[node]-count[child]+N-count[child];
                dfs2(child,node,adj);
            }
        }
    }
public:

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        N=n;
        count.resize(n,1);
        ans.resize(n,0);
        sub.resize(n,0);
        dfs(0,-1,adj);
        ans[0]=sub[0];
        dfs2(0,-1,adj);
        return ans;
    }
};
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        map<int,unordered_set<int>> adj;
        for(auto &it:roads){
            degree[it[0]]++;
            degree[it[1]]++;
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // if(j==i){
                //     continue;
                // }
                int t=degree[i]+degree[j];
                if(adj[i].find(j)!=adj[i].end()){
                    t--;
                }
                ans=max(ans,t);
            }
        }
        return ans;
    }
};
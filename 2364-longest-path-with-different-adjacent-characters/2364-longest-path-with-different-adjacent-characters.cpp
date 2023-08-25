class Solution {
int maxi=0;
private:
    int dfs(int node,vector<vector<int>>&adj,string &s){
        int temp=0;
        int o=0,t=0;
        for(auto &child:adj[node]){
            int temp=dfs(child,adj,s);
            if(s[child]==s[node]){
                temp=0;
            }
            if(temp>o){
                t=o;
                o=temp;
            }
            else if(temp>t){
                t=temp;
            }
        }
        maxi=max(maxi,o+t+1);
        return o+1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>>adj(parent.size());
        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
        }
        return max(maxi,dfs(0,adj,s));
    }
};
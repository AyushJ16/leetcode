class Solution {
private:
    vector<int> topo(vector<vector<int>>& graph, vector<int>& degrees) {
            vector<int> sorted;
            queue<int> q;
            for (int i = 0; i < degrees.size(); ++i) {
                if (degrees[i] == 0) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                sorted.push_back(u);
                for (int v : graph[u]) {
                    degrees[v]--;
                    if (degrees[v] == 0) {
                        q.push(v);
                    }
                }
            }
            return sorted.size() == graph.size() ? sorted : vector<int>();
        };
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(auto &it:group){
            if(it==-1)
            it=m++;
        }
        vector<vector<int> > adj_g(m),adj_i(n);
        unordered_map<int,vector<int>>groupItems;
        // for(int i=0;i<n;i++){
        //     itog[i]=group[i];
        // }
        vector<int>deg_i(n,0),deg_g(m,0);
        for(int i=0;i<n;i++){
            for(auto &bef:beforeItems[i]){
                int from_i=bef;
                int to_i=i;
                int from_g=group[bef];
                int to_g=group[i];
                adj_i[from_i].push_back(to_i);
                deg_i[to_i]++;
                if(from_g!=to_g){
                    adj_g[from_g].push_back(to_g);
                    deg_g[to_g]++;
                }
            }
        }
        vector<int>topo_g=topo(adj_g,deg_g);
        vector<int>topo_i=topo(adj_i,deg_i);
        if(topo_g.empty()||topo_i.empty()){
            return {};
        }
        for(auto &it:topo_i){
            groupItems[group[it]].push_back(it);
        }
        vector<int> ans;
        for(auto &it:topo_g){
            for(auto item:groupItems[it]){
                ans.push_back(item);
            }
        }
        return ans;

    }
};
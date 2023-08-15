class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double> > >adj;
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        vector<double> a;
        for(int i=0;i<queries.size();i++){
            unordered_map<string,int> vis;
            queue <pair<string,double>> q;
            string start=queries[i][0];
            string end=queries[i][1];
            if(adj[start].size()>0)
            q.push({start,1.00000});
            double ans=-1.00000;
            // double cans=1.00000;
            vis[start]=1;
            while(!q.empty()){
                auto it=q.front().first;
                auto cans=q.front().second;
                q.pop();
                if(it==end){
                    ans=cans;
                    break;
                }
                for(auto &t:adj[it]){
                    if(vis[t.first]==0){
                        q.push({t.first,cans*t.second});
                        vis[t.first]=1;
                        // cans*=t.second;
                        if(start=="x"){
                            cout<<cans*t.second;
                            cout<<" "<<t.first<<endl;
                        }
                    }
                }

            }
            a.push_back(ans);
        }
    return a;
    }
};
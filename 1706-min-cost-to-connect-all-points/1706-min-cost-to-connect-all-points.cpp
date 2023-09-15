class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int,int>,int>vis;
        map<pair<int,int>,vector<tuple<int,int,int>>>adj;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        map<pair<int,int>,int>dis;
        pq.push({0,points[0][0],points[0][1]});
        // vis[{points[0][0],points[0][1]}]=1;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i!=j){
                    adj[{points[i][0],points[i][1]}].push_back({points[j][0],points[j][1],abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
                }
            }
        }
        
        int ans=0;
        while(!pq.empty()){
            auto[cw,cx,cy]=pq.top();
            // cout<<cx<<" "<<cy<<" "<<cw<<" "<<vis[{cx,cy}]<<endl;
            pq.pop();
            if(vis[{cx,cy}]==1){
                continue;
            }
            ans+=cw;
            vis[{cx,cy}]=1;
            cout<<adj[{cx,cy}].size()<<endl;
            for(int i=0;i<adj[{cx,cy}].size();i++){
                // cout<<"y"<<endl;
                auto [nx,ny,nw]=adj[{cx,cy}][i];
                // cout<<vis[{nx,ny}]<<" "<<dis[{nx,ny}]<<" "<<nx<<" "<<ny<<endl;
                if(vis[{nx,ny}]==0||dis.find({nx,ny})==dis.end()||nw<dis[{nx,ny}]){
                    dis[{nx,ny}]=nw;
                    pq.push({nw,nx,ny});
                }
            }
        }
        return ans;
    }
};
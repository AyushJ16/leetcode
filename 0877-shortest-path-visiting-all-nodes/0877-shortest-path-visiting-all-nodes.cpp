class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1){
            return 0;
        }
        int all=(1<<n) -1;
        cout<<all<<endl;;
        queue<tuple<int,int,int>>q;
        set<pair<int,int>>st;
        for(int i=0;i<n;i++){
            q.push({i,0,1<<i});
            st.insert({i,i<<i});
        }
        while(!q.empty()){
            auto[curr,dis,mask]=q.front();
            q.pop();
            cout<<curr<<" "<<mask<<endl;
            for(auto &next:graph[curr]){
                int newMask=(mask|(1<<next));
                cout<<newMask<<endl;
                if(newMask==all){
                    return dis+1;
                }
                if(st.find({next,newMask})!=st.end()){
                    continue;
                }
                q.push({next,dis+1,newMask});
                st.insert({next,newMask});
            }
        }
        return -1;


    }
};
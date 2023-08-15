class Disjointset{
public:
    vector <int> parent;vector<int>size;
    Disjointset(int n){
        // n=d;
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUParent(int v){
        if(parent[v]==v){
            return v;
        }
        return parent[v]=findUParent(parent[v]);
    }
    void unionBySize(int u,int v){
        int up_u=findUParent(u);
        int up_v=findUParent(v);
        if(up_u==up_v){
            return;
        }
        if(size[up_u]>=size[up_v]){
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
        else{
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        return;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        Disjointset ds(n);
        unordered_map<int,string>ntm;
        for(int i=0;i<n;i++){
            ntm[i]=accounts[i][0];
        }
        unordered_map<string,int>mtn;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mtn.find(accounts[i][j])==mtn.end()){
                    mtn[accounts[i][j]]=i;
                }
                else{
                    ds.unionBySize(mtn[accounts[i][j]],i);
                    // mtn[accounts[i][j]]=ds.findUParent(i);
                }
            }
        }
        vector<vector<string> > ans1(n);
        // for(int i=0;i<n;i++){
            // vector<int>temp;
            // temp.push_back(ntm[i]);
        for(auto &mails:mtn){
            ans1[ds.findUParent(mails.second)].push_back(mails.first);
        }
        vector <vector<string> > ans;
        for(int i=0;i<n;i++){
            if(ans1[i].size()==0){
                continue;
            }
            sort(ans1[i].begin(),ans1[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &mails:ans1[i]){
                temp.push_back(mails);
            }
            ans.push_back(temp);
        }
        // for(int i=0;i<n;i++){
        //     if(ans1[i].size()==0)
        //     continue;
        //     vector <string> temp;
        //     sort(ans1[i].begin(),ans[i].end());
        //     temp.push_back(accounts[i][0]);
        //     // if(ans1[i].size()>0){
        //     for(auto &m:ans1[i]){
        //         temp.push_back(m);
        //     }
        //         // }
        //     ans.push_back(temp);
        // }
        sort(ans.begin(),ans.end());
        return ans;
        // return {};
        
    }
};
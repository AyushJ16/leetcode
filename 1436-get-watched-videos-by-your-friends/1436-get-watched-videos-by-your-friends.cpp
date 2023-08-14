class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int l=-1;
        vector<vector<int> > adj(friends.size());
        for(int i=0;i<friends.size();i++){
            for(auto &it:friends[i]){
                adj[i].push_back(it);
            }
        }
        vector<int> vis(friends.size(),0);
        queue<pair<int,int>> q;
        q.push({id,-1});
        while(!q.empty()){
            l++;
            if(l==level){
                break;
            }
            int size=q.size();
            for(int i=0;i<size;i++){
                int curr=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(auto & it: adj[curr]){
                    if(it!=parent && vis[it]==0){
                        q.push({it,curr});
                        vis[it]=1;
                    }
                }


            }

        }
        map<string,int> mp;
        while(!q.empty()){
            int curr=q.front().first;
            q.pop();
            for(int i=0;i<watchedVideos[curr].size();i++){
                mp[watchedVideos[curr][i]]++;
            }
        }
        vector<pair<int,string> >ans1;
        vector<string>ans;
        for(auto &it:mp){
            ans1.push_back({it.second,it.first});
        }
        sort(ans1.begin(),ans1.end());
        for(auto &it:ans1){
            ans.push_back(it.second);
        }
        return ans;

    }
};
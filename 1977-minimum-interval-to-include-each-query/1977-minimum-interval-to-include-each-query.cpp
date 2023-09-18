class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>q=queries;
        int n=queries.size();
        int m=intervals.size();
        sort(q.begin(),q.end());
        sort(intervals.begin(),intervals.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>aq;
        vector<int>ans;
        int j=0;
        for(auto q:q){
            while(j<m && intervals[j][0]<=q){
                int l=intervals[j][0];
                int r=intervals[j][1];
                pq.push({r-l+1,r});
                j++;
            }
            while(!pq.empty() && pq.top().second<q){
                pq.pop();
            }
            if(pq.size()){
                aq[q]=pq.top().first;
            }
            else{
                aq[q]=-1;
            }
        }
        for(auto q:queries){
            ans.push_back(aq[q]);
        }
        return ans;
    }
};
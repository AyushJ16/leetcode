class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> merged(2);
        merged=intervals[0];
        intervals.push_back({INT_MAX,INT_MAX});
        for(int i=1;i<intervals.size();i++){
            if(merged[1]<intervals[i][0]){
                ans.push_back(merged);
                merged=intervals[i];
            }
            else if(merged[1]>=intervals[i][0]){
                merged[0]=min(merged[0],intervals[i][0]);
                merged[1]=max(merged[1],intervals[i][1]);
            }
        }
        return ans;

    }
};
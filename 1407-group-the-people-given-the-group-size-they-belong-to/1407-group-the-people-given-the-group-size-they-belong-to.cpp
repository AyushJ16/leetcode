class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>grp;
        vector<vector<int>>result;
        int n=groupSizes.size();
        for(int i=0;i<n;i++){
            grp[groupSizes[i]].push_back(i);
        }
        for(auto &s:grp){
            int size=s.first;
            vector<int>temp(size);
            int t=0;
            for(auto & people:s.second){
                temp[t]=people;
                t++;
                if(t==size){
                    result.push_back(temp);
                    t=0;
                }
            }
        }
        return result;
    }
};
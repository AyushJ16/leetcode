class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int> > grps;
        for(int i=0;i<strs.size();i++){
            string a=strs[i];
            sort(a.begin(),a.end());
            grps[a].push_back(i);
        }
        vector<vector<string> >ans;

        for(auto &grp:grps){
            vector<string>temp;
            for (auto &e:grp.second){
                temp.push_back(strs[e]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
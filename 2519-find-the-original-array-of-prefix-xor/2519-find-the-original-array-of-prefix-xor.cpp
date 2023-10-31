class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector <int> ans;
        int j=0;
        for (int i=0;i<pref.size();i++){
            ans.push_back(pref[i]^j);
            j=pref[i];
        }
        return ans;
    }
};
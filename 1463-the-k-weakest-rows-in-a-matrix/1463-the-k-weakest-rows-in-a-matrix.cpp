class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<int,int>ans;
        vector<int>res(k);
        int sum=0;
        for(int i=0;i<mat.size();i++){
            for(auto &j:mat[i]){
                sum+=j;
            }
            ans.insert({sum,i});
            sum=0;
        }
        int i=0;
        for(auto &t:ans){
            res[i]=t.second;
            i++;
            if(i==k){
                break;
            }
        }
        return res;
    }
};
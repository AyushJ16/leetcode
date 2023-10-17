class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>start,end;
        for(auto flower:flowers){
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int>ans;
        for(int t:people){
            int s=upper_bound(start.begin(),start.end(),t)-start.begin();
            int e=lower_bound(end.begin(),end.end(),t)-end.begin();
            ans.push_back(s-e);
        }
        return ans;

    }
};
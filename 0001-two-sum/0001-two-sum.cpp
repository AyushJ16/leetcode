class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> vis;
        for(int i=0;i<nums.size();i++){
            int req=target-nums[i];
            if(vis.find(req)!=vis.end()){
                return {vis[req],i};
            }
            vis[nums[i]]=i;
        }
        return {};
    }
};
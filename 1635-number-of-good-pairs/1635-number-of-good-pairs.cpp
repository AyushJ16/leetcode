class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int c[101]={0};
        int ans=0;
        for(int i=0;i<nums.size();i++){
            c[nums[i]]++;
            ans+=(c[nums[i]]-1);
        }
        return ans;
    }
};
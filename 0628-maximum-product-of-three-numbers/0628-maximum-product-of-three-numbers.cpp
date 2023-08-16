class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ans=-1e9;
        sort(nums.begin(),nums.end());
        ans=max(ans,nums[0]*nums[1]*nums[nums.size()-1]);
        ans=max(ans,nums[nums.size()-3]*nums[nums.size()-2]*nums[nums.size()-1]);
        return ans;
        
    }
};
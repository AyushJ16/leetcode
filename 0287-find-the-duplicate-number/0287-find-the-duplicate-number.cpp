class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int ans=nums[0];
        int n=nums.size();
        vector<int>mp(n,0);
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                return nums[i];
            }
        }
        return -1;
    }
};
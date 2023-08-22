class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int r=0;
        int mini=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                maxi=0;
                mini=0;
            }
            if(nums[i]<0){
                swap(mini,maxi);
            }
            if(mini>0 || nums[i]<0)mini++;
            if(maxi>0 || nums[i]>0)maxi++;
            r=max(r,maxi);
        }
        return r;
    }
};
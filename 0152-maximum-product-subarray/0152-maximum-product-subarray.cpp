class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi,mini;
        maxi=mini=nums[0];
        int r=mini;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                int temp=mini;
                mini=maxi;
                maxi=temp;
            }
            mini=min(nums[i],mini*nums[i]);
            maxi=max(nums[i],maxi*nums[i]);
            r=max(r,maxi);
        }
        return r;
    }
};
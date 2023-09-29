class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        int n=nums.size();
        int up=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                if(up==-1){
                    return false;
                }
                up=1;
            }
            else if(nums[i]<nums[i-1]){
                if(up==1){
                    return false;
                }
                up=-1;
            }
            else{
                continue;
            }
        }
        return true;
        // if(nums[1]<nums[0])
    }
};
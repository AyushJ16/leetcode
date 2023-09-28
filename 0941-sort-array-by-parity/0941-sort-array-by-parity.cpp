class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        if(j==-1){
            return {};
        }
        while(i<=j){
            if(nums[i]%2==1 && nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++,j--;
                // continue;
            }
            else if(nums[i]%2==0 && nums[j]%2==0){
                i++;
            }
            else if(nums[i]%2==1 && nums[j]%2==1){
                j--;
            }
            else{
                i++;j--;
            }
        }
        return nums;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool f=false;
        for(auto &e:nums){
            if(e==1){
                f=true;
                break;
            }
        }
        if(!f){
            return 1;
        }
        for(auto &e:nums){
            if(e<=0 || e > nums.size()){
                e=1;
            }
        }
        for(int i=0;i<nums.size();i++){
            int a=abs(nums[i]);
            if(a==nums.size()){
                nums[0]=-abs(nums[0]);
            }
            else{
                nums[a]=-abs(nums[a]);
            }
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]>0){
                return i;
            }
        }
        if(nums[0]>0){
            return nums.size();
        }
        return nums.size()+1;

    }
};
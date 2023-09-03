class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int l=-1,mink=-1,maxk=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                l=i;
            }
            if(nums[i]==minK){
                mink=i;
            }
            if(nums[i]==maxK){
                maxk=i;
            }

            ans+=max(0,min(mink,maxk)-l);
        }
        return ans;

    }
};
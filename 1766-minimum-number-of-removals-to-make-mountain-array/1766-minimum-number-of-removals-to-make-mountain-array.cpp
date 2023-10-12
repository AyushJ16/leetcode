class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>l(n,1),r(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    l[i]=max(l[i],l[j]+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[i]){
                    r[i]=max(r[i],r[j]+1);
                }
            }
        }
        for(int i=0;i<n-1;i++){
            if(r[i]>1 && l[i]>1)
            ans=max(ans,r[i]+l[i]-1);
        }
        return n-ans;
    }
};
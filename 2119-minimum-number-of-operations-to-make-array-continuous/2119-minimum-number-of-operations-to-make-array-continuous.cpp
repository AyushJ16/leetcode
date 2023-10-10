class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[l++]=nums[i];
            }
        }
        int ans=nums.size();
        for(int i=0,j=0;i<l;i++){
            while(j<l && nums[j]-nums[i]<=(n-1)){
                j++;
            }
            // cout<<(j-i)<<endl;
            ans=min(ans,n-(j-i));
        }
        return ans;
    }
};
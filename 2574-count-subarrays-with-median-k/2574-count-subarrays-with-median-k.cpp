class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n=nums.size();
        int ind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==k){
                ind=i;
                nums[i]=0;
            }
            else{
                if(nums[i]<k){
                    nums[i]=-1;
                }
                else{
                    nums[i]=1;
                }
            }
        }
        int sum=0;
        int ans=0;
        for(int i=ind-1;i>=0;i--){
            sum+=nums[i];
            freq[sum]++;
            if(sum==0 || sum==1){
                ans++;
            }

        }
        // cout<<ans<<endl;
        sum=0;
        for(int i=ind+1;i<n;i++){
            sum+=nums[i];
            if(sum==0 || sum==1){
                ans++;
            }
            ans+=freq[-sum];
            ans+=freq[1-sum];
        }
        return ans+1;
    }
};
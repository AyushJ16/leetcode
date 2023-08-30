class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        int prev=INT_MAX;
        int pos=n-1;
        int current;
        long long ans=0;
        while(pos>=0){
            if(nums[pos]<=prev){
                prev=nums[pos];
                pos--;
            }
            else{
                int current=nums[pos];
                long long t=current/prev;
                if(current%prev){
                    t++;
                }
                prev=current/(t);
                ans+=t-1;
                pos--;
            }
        }
        return ans;
    }
};
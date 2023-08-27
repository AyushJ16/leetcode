class Solution {
private:
    bool check(vector<int>&nums,int m,int x){
        set<int>st;
        int n=nums.size();
        for(int i=x;i<n;i++){
            st.insert(nums[i-x]);
            auto it=st.lower_bound(nums[i]);
            if(it==st.end()){
                it--;
            }
            if(abs(nums[i]-*(it))<=m){
                return true;
            }
            if(st.find(nums[i])==st.end()){
                if(it!=st.begin()){
                    it--;
                }
                if(abs(nums[i]-*(it))<=m){
                    return true;
                }
            }
            else{
                it++;
                return abs(nums[i]-*(it))<=m;
            }

            
        }
        return false;
    }
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int l=0,r=maxi-mini;
        int res=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(nums,mid,x)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};
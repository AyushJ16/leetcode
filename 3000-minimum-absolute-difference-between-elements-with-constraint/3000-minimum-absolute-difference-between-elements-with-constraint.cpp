class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> st;
        int mini=INT_MAX;
        for(int i=x;i<nums.size();i++){
            st.insert(nums[i-x]);
            auto it=st.lower_bound(nums[i]);
            if(it==st.end()){
                it--;
            }
            mini=min(mini,abs(nums[i]-*(it)));
            if(st.find(nums[i])==st.end()){
                if(it!=st.begin()){
                    it--;
                }
                mini=min(mini,abs(nums[i]-*(it)));
            }
            else{
                it++;
                mini=min(mini,abs(nums[i]-*(it)));
            }


        }
        return mini;
        
    }
};
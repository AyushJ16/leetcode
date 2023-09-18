class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int>st;
        int mp=n-k;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(nums[i]);
            }
            else{
                while(!st.empty() && st.top()>nums[i] && mp>0 && st.size()+n-i-1 >= (k)){
                    if(st.size()+n-i-1 < (k)){
                        break;
                    }
                    mp--;
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        cout<<st.size()<<endl;
        while(st.size()>k){
            cout<<st.top()<<" ";
            st.pop();
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};